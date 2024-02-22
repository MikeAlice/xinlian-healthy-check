#include "stdafx.h"
#include "PreviewEntrustService.h"
#include <string>  
#include <algorithm>  
#include<iostream>
#include <filesystem> 
#include "PdfComponent.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "../../domain/do/preview-entrust/PreviewEntrustDO.h"
#include "../../dao/preview-entrust/PreviewEntrustDAO.h"
//#include "../../../lib-common/include/CharsetConvertHepler.h"

/**
 * �滻��$$��ʶ���ַ�
 * s�����滻��string
 * obj���滻����Դ����DO
 * var�����滻���ַ�
 * func����ȡ�滻���ݵ�get����
 */
#define REPLACE(s, obj, var, func) \
std::string replaced_##func = obj.get##func(); \
size_t pos_##var = s.find(#var); \
while (pos_##var != std::string::npos) { \
		s.replace(pos_##var, std::string(#var).length(), replaced_##func); \
		pos_##var = s.find(#var, pos_##var + replaced_##func.length()); \
}

/**
 * ��װ��Ԫ��yaml��string��list����table��
 */
#define DIVIDE(list,ss,str) \
list.clear(); \
while (std::getline(ss, str, ',')) { \
list.push_back(str); \
}

/**
 * ��ʽ������
 */
#define FORMATTIEM(obj,func,date) \
date = obj.get##func(); \
date.replace(4,1,u8"��"); \
date.replace(9, 1, u8"��"); \
date.replace(14, 1, u8"��"); \
obj.set##func(date.substr(0,17));


/**
 * ���paragraph��line
 */
void splitString(std::list<std::string>&result, std::string & input, size_t size) {
	result.clear();
	std::string current;
	std::string sub_str = u8"\\n";
	size_t pos = 0;

	while ((pos = input.find(sub_str)) != std::string::npos)   //�滻����ָ���Ӵ�
	{
		input.replace(pos, sub_str.length(), "\n");
	}

	std::stringstream ss;
	std::string tmp;
	int linesize = 0;
	ss << input;
	while (std::getline(ss, current))  //�ֽ�utf8�ַ��������� utf8ռλ3��
	{   //δ����������Զ�����
		//std::cout<<current<<std::endl;
		current.insert(0, u8"    ");
		int num = current.size();
		int i = 0;
		string subWord;
		while (i < num)
		{
			int tmpsize = 1;
			if (current[i] & 0x80)
			{
				char temp = current[i];
				temp <<= 1;
				do {
					temp <<= 1;
					++tmpsize;
				} while (temp & 0x80);
			}
			if (tmpsize == 3) linesize += 2;
			else linesize += 1;
			subWord += current.substr(i, tmpsize);
			if (linesize >= size || (i + tmpsize) >= num)
			{
				result.push_back(subWord);
				subWord = "";
				linesize = 0;
			}
			i += tmpsize;
		}
	}
}

std::string PreviewEntrustService::getInfo(const std::string & orderId)
{
	PreviewEntrustDAO dao;
	std::string url;
 	std::string text;
	std::list<std::string> list;

	//��ѯ�Ƿ����к�ͬ
	std::list<PreviewEntrustUrlDO> urlListDO=dao.selectUrl(orderId);
	url=urlListDO.front().getOrderPath();
// 	for(PreviewEntrustUrlDO urlDO : urlListDO)
// 		url=urlDO.getOrderPath();
	if (!url.empty())
		return url;

	//��ѯ��Ϣ
	std::list<PreviewEntrustInfoDO> infoListDO = dao.selectInfo(orderId);
	PreviewEntrustInfoDO info = infoListDO.front();

	//��װģ��
	PdfComponent pdf;
	// ����һ��ҳ��
	HPDF_Page newPage = pdf.getNewPage();
	// ����
	// ����ģ�������ļ�
	auto file = YAML::LoadFile("tpl/entrust.yaml");
	YAML::Node* node=&file;
	// ����ҳ������
	HPDF_UseCNSFonts(pdf.getDoc());
	HPDF_UseCNSEncodings(pdf.getDoc());
	auto titlefont = HPDF_GetFont(pdf.getDoc(), "SimHei", "GBK-EUC-H");
	auto textfont = HPDF_GetFont(pdf.getDoc(), "SimSun", "GBK-EUC-H");
	//��ȡҳ����
	auto height = HPDF_Page_GetHeight(newPage);
	auto width = HPDF_Page_GetWidth(newPage);

	//����
	HPDF_Page_SetFontAndSize(newPage, titlefont, 23);	
	text= (*node)["t1"].as<std::string>();
 	pdf.drawTextCenterH(text, height -= 30);

	HPDF_Page_SetFontAndSize(newPage, titlefont, 20);
	text = (*node)["t2"].as<std::string>();
	pdf.drawTextCenterH(text, height -= 25);

	HPDF_Page_SetFontAndSize(newPage, textfont, 15);
	text = (*node)["code"].as<std::string>();
	REPLACE(text, info, $orderCode$, OrderCode);
	pdf.drawText(text,width/3*2, height -= 25);

	//����
	text = (*node)["p1"].as<std::string>();
	std::string date;
	FORMATTIEM(info, StartDate, date);
	FORMATTIEM(info, EndDate, date);
	REPLACE(text, info, $startDate$, StartDate);
	REPLACE(text, info, $endDate$, EndDate);
	splitString(list, text, 60);
	for (std::string cur : list)
	{
		pdf.drawText(cur, 60, height -= 20);
	}

	// ���浽����
	//"./public/pdf/entrust.pdf"
	//"./out/build/x64-Debug/healthy-c3-sales-order/entrust.pdf";
// 	std::filesystem::path curpath = std::filesystem::current_path();
// 	std::cout << "path:\t" << curpath << std::endl;
	std::string fileName = "entrust.pdf";
	std::filesystem::path filePath = fileName;
	pdf.saveDocToFile(fileName);
	// ����DFS�ͻ��˶����URLǰ׺
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// �ϴ�dfs
	std::string fieldName = client.uploadFile(fileName);
	// ɾ������
	if (std::filesystem::remove(filePath)) {
		std::cout << "�����ļ�ɾ���ɹ�!" << std::endl;
	}
	else {
		std::cout << "�����ļ�ɾ��ʧ��!" << std::endl;
	}
	// �ж��Ƿ��ϴ��ɹ�
	if (!fieldName.empty())
	{
		// ��������·��
		url = urlPrefix + fieldName;
		// ����&�������·��
		dao.updateUrl(orderId,url);
	}
	else url = "";
	return url;
}
