#include "stdafx.h"
#include "OtherService.h"
#include <iostream>
#include "PdfComponent.h"
#include "ServerInfo.h"

// ��������������Ҫ����ͷ�ļ�
#include "zxing/MultiFormatWriter.h"
#include "zxing/CharacterSet.h"
#include "zxing/BitMatrix.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>
using namespace ZXing;

// FastDFSʹ����Ҫ�����ͷ�ļ�
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

// ����������Ԥ�� https://zxing-cpp.github.io/zxing-cpp/demo_writer.html
void addBarCodeToPdf(PdfComponent* pdf) {
	// �������������ز���
	int width = 200, height = 20; // ����
	int margin = 10; // ���
	int eccLevel = 0; // ecc�ȼ�0 -10
	CharacterSet encoding = CharacterSet::UTF8; // ����
	BarcodeFormat format = BarcodeFormatFromString("Code93"); //��ʽ������
	// ���������е�����
	std::string input = "11111111";
	// ������ʱ����λ��
	std::string filepath = "tmp.jpg";
	try {
		// ����ͼ��
		auto writer = MultiFormatWriter(format).setMargin(margin).setEncoding(encoding).setEccLevel(eccLevel);
		BitMatrix matrix = writer.encode(input, width, height);
		auto bitmap = ToMatrix<uint8_t>(matrix);
		// ���浽�ļ�
		int success = stbi_write_jpg(filepath.c_str(), bitmap.width(), bitmap.height(), 1, bitmap.data(), 0);
		// ���Ƶ�PDF
		if (success)
		{
			// ����ͼƬ�ļ�
			HPDF_Image image = HPDF_LoadJpegImageFromFile(pdf->getDoc(), filepath.c_str());
			// ����ͼƬ��PDF��
			HPDF_UINT iw = HPDF_Image_GetWidth(image);
			HPDF_UINT ih = HPDF_Image_GetHeight(image);
			HPDF_Page_DrawImage(pdf->getCurrPage(), image, 30, 70, iw, ih);
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void TestPdf::testText()
{
	PdfComponent pdf;
	// ����һ��ҳ��
	HPDF_Page newPage = pdf.getNewPage();
	// ����ҳ������
	HPDF_Page_SetFontAndSize(newPage, pdf.getCnSFont("SimSun"), 20);
	// ��������
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.title"), HPDF_Page_GetHeight(newPage) - 40);
	pdf.drawTextCenter(ZH_WORDS_GETTER("pdf.content"));
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.foot"), 20);
	// ���浽�ļ�
	pdf.saveDocToFile("test-text.pdf");
}

void TestPdf::testTpl()
{
	// ����ע����Ⱦģ��
	PdfComponent::registerTplRender("test", [](YAML::Node* node, PdfComponent* pdf, void* realData)
		{
			// ����һ��ҳ��
			HPDF_Page newPage = pdf->getNewPage();
			// ����ҳ������
			HPDF_Page_SetFontAndSize(newPage, pdf->getCnSFont("SimSun"), 20);
			// ���ƾ�̬����
			auto title = (*node)["t"].as<std::string>();
			auto foot = (*node)["f"].as<std::string>();
			pdf->drawTextCenterH(title, HPDF_Page_GetHeight(newPage)-60);
			pdf->drawTextCenterH(foot, 20);
			// ���ƶ�̬����
			std::string content = static_cast<std::string*>(realData)->c_str();
			pdf->drawTextCenter(content);
			// ����һ������
			//addBarCodeToPdf(pdf);
			// ���浽�ļ�
			pdf->saveDocToFile("test-tpl.pdf");
		});

	// ���Ի���
	PdfComponent pdf;
	auto content = ZH_WORDS_GETTER("pdf.content");
	pdf.drawWithTemplate("tpl/test.yaml", "test", &content);
}


void TestFastDfs::testDfs(string fileName)
{
#ifdef LINUX
	//����ͻ��˶���
	FastDfsClient client("conf/client.conf");
#else
	//����ͻ��˶���
	FastDfsClient client("192.168.142.131");
#endif

	//�����ϴ�
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	//��������
	if (!fieldName.empty())
	{
		std::string path = "./public/fastdfs";
		fileName = client.downloadFile(fieldName, &path);
		std::cout << "download savepath is : " << fileName << std::endl;
	}
	//����ɾ���ļ�
	if (!fieldName.empty())
	{
		std::cout << "delete file result is : " << client.deleteFile(fieldName) << std::endl;
	}
}

string TestFastDfs::testDfsWithConf(string fileName)
{
	//	// ����һ��Nacos�ͻ��˶������ڻ�ȡ����
	//	NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
	//#ifdef LINUX
	//	// ��ȡ�������ݽڵ�
	//	auto thirdServerConfig = ns.getConfig("third-services.yaml");
	//	// ��Nacos�������Ļ�ȡFastDFS�ͻ�����������
	//	std::string config = ns.getConfigText("client.conf");
	//	// ����ͻ��˶���
	//	FastDfsClient client(config, false);
	//#else
	//	// ��ȡ�������ݽڵ�
	//	auto thirdServerConfig = ns.getConfig("./conf/third-services.yaml");
	//	// �������л�ȡFastDFS�ͻ�����������
	//	std::string ipPort = YamlHelper().getString(&thirdServerConfig, "fastdfs.tracker-servers");
	//	std::string ip = ipPort.substr(0, ipPort.find(":"));
	//	int port = stoi(ipPort.substr(ipPort.find(":") + 1));
	//	// ����ͻ��˶���
	//	FastDfsClient client(ip, port);
	//#endif
	//	// ����urlǰ׺
	//	std::string urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";

		// ����DFS�ͻ��˶����URLǰ׺
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// ��ʼ�ϴ��ļ�
	std::string fieldName = client.uploadFile(fileName);
	// ��������·��
	std::string downloadUrl = urlPrefix + fieldName;
	// �������·��
	//std::cout << "download url: " << downloadUrl << std::endl;
	return downloadUrl;
}

