#include "stdafx.h"
#include "OtherService.h"
#include <iostream>
#include "PdfComponent.h"
#include "ServerInfo.h"

// 条形码码生成需要导入头文件
#include "zxing/MultiFormatWriter.h"
#include "zxing/CharacterSet.h"
#include "zxing/BitMatrix.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb/stb_image_write.h>
using namespace ZXing;

// FastDFS使用需要的相关头文件
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

// 条形码在线预览 https://zxing-cpp.github.io/zxing-cpp/demo_writer.html
void addBarCodeToPdf(PdfComponent* pdf) {
	// 设置条码绘制相关参数
	int width = 200, height = 20; // 长宽
	int margin = 10; // 间距
	int eccLevel = 0; // ecc等级0 -10
	CharacterSet encoding = CharacterSet::UTF8; // 编码
	BarcodeFormat format = BarcodeFormatFromString("Code93"); //格式化类型
	// 定义条码中的内容
	std::string input = "11111111";
	// 条码临时保存位置
	std::string filepath = "tmp.jpg";
	try {
		// 生成图形
		auto writer = MultiFormatWriter(format).setMargin(margin).setEncoding(encoding).setEccLevel(eccLevel);
		BitMatrix matrix = writer.encode(input, width, height);
		auto bitmap = ToMatrix<uint8_t>(matrix);
		// 保存到文件
		int success = stbi_write_jpg(filepath.c_str(), bitmap.width(), bitmap.height(), 1, bitmap.data(), 0);
		// 绘制到PDF
		if (success)
		{
			// 加载图片文件
			HPDF_Image image = HPDF_LoadJpegImageFromFile(pdf->getDoc(), filepath.c_str());
			// 绘制图片到PDF中
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
	// 创建一个页面
	HPDF_Page newPage = pdf.getNewPage();
	// 设置页面字体
	HPDF_Page_SetFontAndSize(newPage, pdf.getCnSFont("SimSun"), 20);
	// 绘制字体
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.title"), HPDF_Page_GetHeight(newPage) - 40);
	pdf.drawTextCenter(ZH_WORDS_GETTER("pdf.content"));
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.foot"), 20);
	// 保存到文件
	pdf.saveDocToFile("test-text.pdf");
}

void TestPdf::testTpl()
{
	// 测试注册渲染模板
	PdfComponent::registerTplRender("test", [](YAML::Node* node, PdfComponent* pdf, void* realData)
		{
			// 创建一个页面
			HPDF_Page newPage = pdf->getNewPage();
			// 设置页面字体
			HPDF_Page_SetFontAndSize(newPage, pdf->getCnSFont("SimSun"), 20);
			// 绘制静态数据
			auto title = (*node)["t"].as<std::string>();
			auto foot = (*node)["f"].as<std::string>();
			pdf->drawTextCenterH(title, HPDF_Page_GetHeight(newPage)-60);
			pdf->drawTextCenterH(foot, 20);
			// 绘制动态数据
			std::string content = static_cast<std::string*>(realData)->c_str();
			pdf->drawTextCenter(content);
			// 绘制一个条码
			//addBarCodeToPdf(pdf);
			// 保存到文件
			pdf->saveDocToFile("test-tpl.pdf");
		});

	// 测试绘制
	PdfComponent pdf;
	auto content = ZH_WORDS_GETTER("pdf.content");
	pdf.drawWithTemplate("tpl/test.yaml", "test", &content);
}


void TestFastDfs::testDfs(string fileName)
{
#ifdef LINUX
	//定义客户端对象
	FastDfsClient client("conf/client.conf");
#else
	//定义客户端对象
	FastDfsClient client("192.168.142.131");
#endif

	//测试上传
	std::string fieldName = client.uploadFile(fileName);
	std::cout << "upload fieldname is : " << fieldName << std::endl;
	//测试下载
	if (!fieldName.empty())
	{
		std::string path = "./public/fastdfs";
		fileName = client.downloadFile(fieldName, &path);
		std::cout << "download savepath is : " << fileName << std::endl;
	}
	//测试删除文件
	if (!fieldName.empty())
	{
		std::cout << "delete file result is : " << client.deleteFile(fieldName) << std::endl;
	}
}

string TestFastDfs::testDfsWithConf(string fileName)
{
	//	// 定义一个Nacos客户端对象，用于获取配置
	//	NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
	//#ifdef LINUX
	//	// 读取配置数据节点
	//	auto thirdServerConfig = ns.getConfig("third-services.yaml");
	//	// 从Nacos配置中心获取FastDFS客户端配置数据
	//	std::string config = ns.getConfigText("client.conf");
	//	// 定义客户端对象
	//	FastDfsClient client(config, false);
	//#else
	//	// 读取配置数据节点
	//	auto thirdServerConfig = ns.getConfig("./conf/third-services.yaml");
	//	// 从配置中获取FastDFS客户端配置数据
	//	std::string ipPort = YamlHelper().getString(&thirdServerConfig, "fastdfs.tracker-servers");
	//	std::string ip = ipPort.substr(0, ipPort.find(":"));
	//	int port = stoi(ipPort.substr(ipPort.find(":") + 1));
	//	// 定义客户端对象
	//	FastDfsClient client(ip, port);
	//#endif
	//	// 设置url前缀
	//	std::string urlPrefix = "http://" + YamlHelper().getString(&thirdServerConfig, "fastdfs.nginx-servers") + "/";

		// 定义DFS客户端对象和URL前缀
	ZO_CREATE_DFS_CLIENT_URL(client, urlPrefix);
	// 开始上传文件
	std::string fieldName = client.uploadFile(fileName);
	// 构建下载路径
	std::string downloadUrl = urlPrefix + fieldName;
	// 输出下载路径
	//std::cout << "download url: " << downloadUrl << std::endl;
	return downloadUrl;
}

