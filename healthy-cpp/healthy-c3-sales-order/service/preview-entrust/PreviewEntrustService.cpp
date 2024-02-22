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
 * 替换以$$标识的字符
 * s：待替换的string
 * obj：替换数据源，即DO
 * var：待替换的字符
 * func：获取替换数据的get方法
 */
#define REPLACE(s, obj, var, func) \
std::string replaced_##func = obj.get##func(); \
size_t pos_##var = s.find(#var); \
while (pos_##var != std::string::npos) { \
		s.replace(pos_##var, std::string(#var).length(), replaced_##func); \
		pos_##var = s.find(#var, pos_##var + replaced_##func.length()); \
}

/**
 * 分装单元格，yaml→string→list（→table）
 */
#define DIVIDE(list,ss,str) \
list.clear(); \
while (std::getline(ss, str, ',')) { \
list.push_back(str); \
}

/**
 * 格式化日期
 */
#define FORMATTIEM(obj,func,date) \
date = obj.get##func(); \
date.replace(4,1,u8"年"); \
date.replace(9, 1, u8"月"); \
date.replace(14, 1, u8"日"); \
obj.set##func(date.substr(0,17));


/**
 * 拆分paragraph和line
 */
void splitString(std::list<std::string>&result, std::string & input, size_t size) {
	result.clear();
	std::string current;
	std::string sub_str = u8"\\n";
	size_t pos = 0;

	while ((pos = input.find(sub_str)) != std::string::npos)   //替换所有指定子串
	{
		input.replace(pos, sub_str.length(), "\n");
	}

	std::stringstream ss;
	std::string tmp;
	int linesize = 0;
	ss << input;
	while (std::getline(ss, current))  //分解utf8字符串（中文 utf8占位3）
	{   //未解决：标点的自动换行
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

	//查询是否已有合同
	std::list<PreviewEntrustUrlDO> urlListDO=dao.selectUrl(orderId);
	url=urlListDO.front().getOrderPath();
// 	for(PreviewEntrustUrlDO urlDO : urlListDO)
// 		url=urlDO.getOrderPath();
	if (!url.empty())
		return url;

	//查询信息
	std::list<PreviewEntrustInfoDO> infoListDO = dao.selectInfo(orderId);
	PreviewEntrustInfoDO info = infoListDO.front();

	//组装模板
	PdfComponent pdf;
	// 创建一个页面
	HPDF_Page newPage = pdf.getNewPage();
	// 绘制
	// 加载模板配置文件
	auto file = YAML::LoadFile("tpl/entrust.yaml");
	YAML::Node* node=&file;
	// 设置页面字体
	HPDF_UseCNSFonts(pdf.getDoc());
	HPDF_UseCNSEncodings(pdf.getDoc());
	auto titlefont = HPDF_GetFont(pdf.getDoc(), "SimHei", "GBK-EUC-H");
	auto textfont = HPDF_GetFont(pdf.getDoc(), "SimSun", "GBK-EUC-H");
	//获取页面宽高
	auto height = HPDF_Page_GetHeight(newPage);
	auto width = HPDF_Page_GetWidth(newPage);

	//标题
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

	//正文
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

	// 保存到本地
	//"./public/pdf/entrust.pdf"
	//"./out/build/x64-Debug/healthy-c3-sales-order/entrust.pdf";
// 	std::filesystem::path curpath = std::filesystem::current_path();
// 	std::cout << "path:\t" << curpath << std::endl;
	std::string fileName = "entrust.pdf";
	std::filesystem::path filePath = fileName;
	pdf.saveDocToFile(fileName);
	// 定义DFS客户端对象和URL前缀
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// 上传dfs
	std::string fieldName = client.uploadFile(fileName);
	// 删除本地
	if (std::filesystem::remove(filePath)) {
		std::cout << "本地文件删除成功!" << std::endl;
	}
	else {
		std::cout << "本地文件删除失败!" << std::endl;
	}
	// 判断是否上传成功
	if (!fieldName.empty())
	{
		// 构建下载路径
		url = urlPrefix + fieldName;
		// 保存&输出下载路径
		dao.updateUrl(orderId,url);
	}
	else url = "";
	return url;
}
