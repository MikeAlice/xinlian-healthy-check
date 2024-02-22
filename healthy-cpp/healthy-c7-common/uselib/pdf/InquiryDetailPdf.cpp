/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/12/29 11:30:58

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "InquiryDetailPdf.h"
#include <iostream>
#include "PdfComponent.h"
#include "ServerInfo.h"

// 条形码码生成需要导入头文件
//#include "zxing/MultiFormatWriter.h"
//#include "zxing/CharacterSet.h"
//#include "zxing/BitMatrix.h"
//#define STB_IMAGE_WRITE_IMPLEMENTATION
//#include <stb/stb_image_write.h>
//using namespace ZXing;
//
// //条形码在线预览 https://zxing-cpp.github.io/zxing-cpp/demo_writer.html
//void addBarCodeToPdf(PdfComponent* pdf) {
//	// 设置条码绘制相关参数
//	int width = 200, height = 20; // 长宽
//	int margin = 10; // 间距
//	int eccLevel = 0; // ecc等级0 -10
//	CharacterSet encoding = CharacterSet::UTF8; // 编码
//	BarcodeFormat format = BarcodeFormatFromString("Code93"); //格式化类型
//	// 定义条码中的内容
//	std::string input = "11111111";
//	// 条码临时保存位置
//	std::string filepath = "tmp.jpg";
//	try {
//		// 生成图形
//		auto writer = MultiFormatWriter(format).setMargin(margin).setEncoding(encoding).setEccLevel(eccLevel);
//		BitMatrix matrix = writer.encode(input, width, height);
//		auto bitmap = ToMatrix<uint8_t>(matrix);
//		// 保存到文件
//		int success = stbi_write_jpg(filepath.c_str(), bitmap.width(), bitmap.height(), 1, bitmap.data(), 0);
//		// 绘制到PDF
//		if (success)
//		{
//			// 加载图片文件
//			HPDF_Image image = HPDF_LoadJpegImageFromFile(pdf->getDoc(), filepath.c_str());
//			// 绘制图片到PDF中
//			HPDF_UINT iw = HPDF_Image_GetWidth(image);
//			HPDF_UINT ih = HPDF_Image_GetHeight(image);
//			HPDF_Page_DrawImage(pdf->getCurrPage(), image, 30, 70, iw, ih);
//		}
//	}
//	catch (const std::exception& e) {
//		std::cerr << e.what() << std::endl;
//	}
//}

//void InquiryDetailPdf::InquiryDetailTpl()
//{
//	// 测试注册渲染模板
//	PdfComponent::registerTplRender("InquiryDetail", [](YAML::Node* node, PdfComponent* pdf, void* realData)
//		{
//			// 创建一个页面
//			HPDF_Page newPage = pdf->getNewPage();
//			// 设置页面字体
//			HPDF_Page_SetFontAndSize(newPage, pdf->getCnSFont("SimSun"), 20);
//			// 绘制静态数据
//			auto title = (*node)["t"].as<std::string>();
//			auto id = (*node)["id"].as<std::string>();
//			auto workYear = (*node)["workYear"].as<std::string>();
//			auto workMonth = (*node)["workMonth"].as<std::string>();
//			auto isMarry = (*node)["isMarry"].as<std::string>();
//			auto exposureWorkYear = (*node)["exposureWorkYear"].as<std::string>();
//			auto exposureWorkMonth = (*node)["exposureWorkMonth"].as<std::string>();
//			auto education = (*node)["education"].as<std::string>();
//			auto familyAddress = (*node)["familyAddress"].as<std::string>();
//			auto workTypeText = (*node)["workTypeText"].as<std::string>();
//			auto workName = (*node)["workName"].as<std::string>();
//			auto department = (*node)["department"].as<std::string>();
//
//			pdf->drawTextCenterH(title, HPDF_Page_GetHeight(newPage) - 20);
//			pdf->drawTextCenterH(id, HPDF_Page_GetHeight(newPage) - 20);
//			pdf->drawTextCenterH(workYear, HPDF_Page_GetHeight(newPage) - 20);
//			pdf->drawTextCenterH(workMonth, HPDF_Page_GetHeight(newPage) - 20);
//			pdf->drawTextCenterH(isMarry, HPDF_Page_GetHeight(newPage) - 20);
//			pdf->drawTextCenterH(exposureWorkYear, HPDF_Page_GetHeight(newPage) - 20);
//			pdf->drawTextCenterH(exposureWorkMonth, HPDF_Page_GetHeight(newPage) - 20);
//			pdf->drawTextCenterH(education, HPDF_Page_GetHeight(newPage) - 20);
//			pdf->drawTextCenterH(familyAddress, HPDF_Page_GetHeight(newPage) - 20);
//			pdf->drawTextCenterH(workTypeText, HPDF_Page_GetHeight(newPage) - 20);
//			pdf->drawTextCenterH(workName, HPDF_Page_GetHeight(newPage) - 20);
//			pdf->drawTextCenterH(department, HPDF_Page_GetHeight(newPage) - 20);
//
//
//
//
//			//auto title = (*node)["t"].as<std::string>();
//			//auto foot = (*node)["f"].as<std::string>();
//			//pdf->drawTextCenterH(title, HPDF_Page_GetHeight(newPage) - 20);
//			//pdf->drawTextCenterH(foot, 20);
//			 
//			
//			// 绘制动态数据
//			std::string content = static_cast<std::string*>(realData)->c_str();
//			pdf->drawTextCenter(content);
//			// 绘制一个条码
//			addBarCodeToPdf(pdf);
//			// 保存到文件
//			pdf->saveDocToFile("test-tpl.pdf");
//		});
//	// 测试绘制
//	PdfComponent pdf;
//	auto content = ZH_WORDS_GETTER("pdf.content");
//	pdf.drawWithTemplate("tpl/test.yaml", "InquiryDetail", &content);
//}

void InquiryDetailPdf::InquiryDetailText(const InquiryDetailDO& Do)
{
	PdfComponent pdf;
	// 创建一个页面
	HPDF_Page newPage = pdf.getNewPage(); 
	// 设置页面字体
	HPDF_Page_SetFontAndSize(newPage, pdf.getCnSFont("SimSun"), 20);
	// 绘制字体
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.title") +": " , HPDF_Page_GetHeight(newPage) - 20);
	pdf.drawText(ZH_WORDS_GETTER("pdf.id") +": " + to_string(Do.getId()), 50.0,780.0);
	pdf.drawText(ZH_WORDS_GETTER("pdf.workYear") +": " + to_string(Do.getWorkYear()), 50.0,740.0);
	pdf.drawText(ZH_WORDS_GETTER("pdf.workMonth") +": " + to_string(Do.getWorkMonth()), 250.0,740.0);
	pdf.drawText(ZH_WORDS_GETTER("pdf.isMarry") +": " + Do.getIsMarry(), 50.0,700.0);
	pdf.drawText(ZH_WORDS_GETTER("pdf.exposureWorkYear") +": " + to_string(Do.getExposureWorkYear()), 50.0, 660.0);
	pdf.drawText(ZH_WORDS_GETTER("pdf.exposureWorkMonth") +": " + to_string(Do.getExposureWorkMonth()), 250.0, 660.0);
	pdf.drawText(ZH_WORDS_GETTER("pdf.education") +": " + Do.getEducation(), 50.0, 620.0);
	pdf.drawText(ZH_WORDS_GETTER("pdf.familyAddress") +": " + Do.getFamilyAddress(), 250.0,620.0);
	pdf.drawText(ZH_WORDS_GETTER("pdf.workTypeText") +": " + Do.getWorkTypeText(), 50.0, 580.0);
	pdf.drawText(ZH_WORDS_GETTER("pdf.workName") +": " + Do.getWorkName(), 50, 540.0);
	pdf.drawText(ZH_WORDS_GETTER("pdf.department") +": " + Do.getDepartment(), 50.0, 500.0);



	// 保存到文件
	pdf.saveDocToFile("InquiryDetailReport.pdf");
}
