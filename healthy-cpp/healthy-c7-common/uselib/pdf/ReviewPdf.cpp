#include "stdafx.h"
#include "ReviewPdf.h"
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

void ReviewPdf::reviewText(const ReviewDO& Do)
{
	PdfComponent pdf;
	// 创建一个页面
	HPDF_Page newPage = pdf.getNewPage();
	// 设置页面字体
	HPDF_Page_SetFontAndSize(newPage, pdf.getCnSFont("SimSun"), 20);
	// 绘制字体
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.title"), HPDF_Page_GetHeight(newPage) - 20);
	pdf.drawText(ZH_WORDS_GETTER("pdf.personName") + ": " + Do.getPersonName(), 50.0, 780.0, newPage);
	pdf.drawText(ZH_WORDS_GETTER("pdf.checkProjectName") + ": " + Do.getCheckProjectName(), 50.0, 750.0, newPage);
	pdf.drawText(ZH_WORDS_GETTER("pdf.reviewExplain") + ": " + Do.getReviewExplain(), 50.0, 720.0, newPage);
	pdf.drawText(ZH_WORDS_GETTER("pdf.reviewTime") + ": " + Do.getReviewTime(), 50.0, 690.0, newPage);
	pdf.drawText(ZH_WORDS_GETTER("pdf.createTime") + ": " + Do.getCreateTime(), 50.0, 660.0, newPage);
	std::string state = to_string(Do.getState());
	pdf.drawText(ZH_WORDS_GETTER("pdf.state") + ": " + state, 50.0, 630.0, newPage);
	pdf.drawText(ZH_WORDS_GETTER("pdf.hazardFactorCode") + ": " + Do.getHazardFactorCode(), 50.0, 600.0, newPage);
	pdf.saveDocToFile("ReviewReport.pdf");
}

void ReviewPdf::reviewTpl(const ReviewDO& Do)
{
	// 测试注册渲染模板
	PdfComponent::registerTplRender("ReviewReport", [](YAML::Node* node, PdfComponent* pdf, void* realData)
		{
			// 创建一个页面
			HPDF_Page newPage = pdf->getNewPage();
			// 设置页面字体
			HPDF_Page_SetFontAndSize(newPage, pdf->getCnSFont("SimSun"), 20);
			// 绘制静态数据
			auto title = (*node)["title"].as<std::string>();
			auto personName = (*node)["personName"].as<std::string>();
			auto checkProjectName = (*node)["checkProjectName"].as<std::string>();
			auto reviewExplain = (*node)["reviewExplain"].as<std::string>();
			auto reviewTime = (*node)["reviewTime"].as<std::string>();
			auto createTime = (*node)["createTime"].as<std::string>();
			auto state = (*node)["state"].as<std::string>();
			auto hazardFactorCode = (*node)["hazardFactorCode"].as<std::string>();
			pdf->drawTextCenterH(title, HPDF_Page_GetHeight(newPage) - 20);
			pdf->drawTextCenterH(personName, HPDF_Page_GetHeight(newPage) - 40);
			pdf->drawTextCenterH(checkProjectName, HPDF_Page_GetHeight(newPage) - 60);
			pdf->drawTextCenterH(reviewExplain, HPDF_Page_GetHeight(newPage) - 80);
			pdf->drawTextCenterH(reviewTime, HPDF_Page_GetHeight(newPage) - 100);
			pdf->drawTextCenterH(createTime, HPDF_Page_GetHeight(newPage) - 120);
			pdf->drawTextCenterH(state, HPDF_Page_GetHeight(newPage) - 140);
			pdf->drawTextCenterH(hazardFactorCode, HPDF_Page_GetHeight(newPage) - 160);
			// 绘制动态数据
			std::string content = static_cast<std::string*>(realData)->c_str();
			pdf->drawTextCenter(content);
			// 绘制一个条码
			addBarCodeToPdf(pdf);
			// 保存到文件
			pdf->saveDocToFile("ReviewReport.pdf");
		});

	// 绘制
	PdfComponent pdf;
	auto content = ZH_WORDS_GETTER("pdf.content");
	pdf.drawWithTemplate("tpl/test.yaml", "ReviewReport", &content);
}
