#include "stdafx.h"
#include "Pdf.h"
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
void addBarCodeToPdf(PdfComponent* pdf,string barcodes,int i=0) {
	// 设置条码绘制相关参数
	int width = 200, height = 20; // 长宽
	int margin = 10; // 间距
	int eccLevel = 0; // ecc等级0 -10
	CharacterSet encoding = CharacterSet::UTF8; // 编码
	BarcodeFormat format = BarcodeFormatFromString("Code93"); //格式化类型
	// 定义条码中的内容
	std::string input = "barcodes";
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
			HPDF_Page_DrawImage(pdf->getCurrPage(), image,30,70+i*20, iw, ih);
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

void BarcodesPdf::barcodesText()
{
	PdfComponent pdf;
	// 创建一个页面
	HPDF_Page newPage = pdf.getNewPage();
	// 设置页面字体
	HPDF_Page_SetFontAndSize(newPage, pdf.getCnSFont("SimSun"), 20);
	// 绘制字体
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.title"), HPDF_Page_GetHeight(newPage) - 20);
	pdf.drawTextCenter(ZH_WORDS_GETTER("pdf.content"));
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.foot"), 20);
	// 保存到文件
	pdf.saveDocToFile("test-text.pdf");
}

bool BarcodesPdf::barcodesTpl(oatpp::List<SampleBarcodesViewDTO::Wrapper> ldto,string filename)
{
	
	// 测试绘制
	string content ;
	PdfComponent pdf;
	// 创建一个页面
	HPDF_Page newPage = pdf.getNewPage();
	// 设置页面字体
	HPDF_Page_SetFontAndSize(newPage, pdf.getCnSFont("SimSun"), 20);
	// 绘制字体
	for (int i = 1; i <= ldto->size(); i++) {
		content = ldto[i-1]->person_name + "-" + ldto[i-1]->sex + "-" + std::to_string(ldto[i-1]->age) + "-" + ldto[i-1]->barcode + "-" + ldto[i-1]->group_item_name;
		pdf.drawTextCenterH(content, HPDF_Page_GetHeight(newPage)-i*20);
		addBarCodeToPdf(&pdf, ldto[i-1]->barcode, i);
		content.clear();
	}
	// 保存到文件
	if (!pdf.saveDocToFile(filename))
	{
		return false;
	}
	else {
		return true;
	}
}

bool BarcodesPdf::reportTpl(oatpp::List<ReportPreviewViewDTO::Wrapper> rpdto, oatpp::List<T_symptomDTO::Wrapper> tsdto, string filename)
{
	// 测试绘制
	string content;
	PdfComponent pdf;
	// 创建一个页面
	HPDF_Page newPage = pdf.getNewPage();
	// 设置页面字体
	HPDF_Page_SetFontAndSize(newPage, pdf.getCnSFont("SimSun"), 20);
	// 绘制字体
	auto height = HPDF_Page_GetHeight(newPage);

	pdf.drawText(rpdto[0]->person_name, 10, height - 20);
	pdf.drawText(rpdto[0]->sex, 10, height - 40);
	pdf.drawText(rpdto[0]->id_card, 10, height - 60);
	pdf.drawText(rpdto[0]->birth, 10, height - 80);
	pdf.drawText(std::to_string(rpdto[0]->age), 10, height - 100);
	pdf.drawText(rpdto[0]->home_address, 10, height - 120);
	pdf.drawText(rpdto[0]->mobile, 10, height - 140);
	pdf.drawText(rpdto[0]->test_num, 10, height - 160);
	pdf.drawText(rpdto[0]->department, 10, height - 180);
	pdf.drawText(rpdto[0]->dept, 10, height - 200);
	pdf.drawText(rpdto[0]->check_date, 10, height - 220);
	pdf.drawText(rpdto[0]->other_hazard_factors, 10, height - 240);
	pdf.drawText(rpdto[0]->work_type_text, 10, height - 260);
	pdf.drawText(std::to_string(rpdto[0]->work_year), 10, height - 280);
	pdf.drawText(std::to_string(rpdto[0]->exposure_work_year), 10, height - 3000);
	pdf.drawText(rpdto[0]->education, 10, height - 320);
	pdf.drawText(rpdto[0]->marriage_date, 10, height - 340);
	pdf.drawText(std::to_string(rpdto[0]->period), 10, height - 360);
	pdf.drawText(std::to_string(rpdto[0]->cycle), 10, height - 380);
	pdf.drawText(std::to_string(rpdto[0]->menarche), 10, height - 400);
	pdf.drawText(rpdto[0]->last_menstruation, 10, height - 420);
	pdf.drawText(rpdto[0]->existing_children, 10, height - 440);
	pdf.drawText(rpdto[0]->premature, 10, height - 460);
	pdf.drawText(rpdto[0]->death, 10, height - 480);
	pdf.drawText(rpdto[0]->abnormal_fetus, 10, height - 500);
	pdf.drawText(rpdto[0]->allergies, 10, height - 520);
	pdf.drawText(std::to_string(rpdto[0]->package_every_day), 10, height - 540);
	pdf.drawText(std::to_string(rpdto[0]->ml_every_day), 10, height - 560);
	pdf.drawText(std::to_string(rpdto[0]->drink_year), 10, height - 580);
	pdf.drawText(rpdto[0]->birthplace_name, 10, height - 600);
	pdf.drawText(rpdto[0]->family_history, 10, height - 620);
	pdf.drawText(rpdto[0]->past_medical_history, 10, height - 640);
	pdf.drawText(rpdto[0]->disease_name, 10, height - 660);
	for (int i = 1; i <= tsdto->size(); i++)
	{
		content = "("+tsdto[i - 1]->project_name+")" +"("+ tsdto[i - 1]->degree +")" +"("+ tsdto[i - 1]->course_time+ ")";
		pdf.drawText(content, HPDF_Page_GetWidth(newPage)/2 ,height-i*20);
		content.clear();
	}

	// 保存到文件
	if (!pdf.saveDocToFile(filename))
	{
		return false;
	}
	else {
		return true;
	}
}
