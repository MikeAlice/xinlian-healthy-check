#include "stdafx.h"
#include "Pdf.h"
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

// ����������Ԥ�� https://zxing-cpp.github.io/zxing-cpp/demo_writer.html
void addBarCodeToPdf(PdfComponent* pdf,string barcodes,int i=0) {
	// �������������ز���
	int width = 200, height = 20; // ����
	int margin = 10; // ���
	int eccLevel = 0; // ecc�ȼ�0 -10
	CharacterSet encoding = CharacterSet::UTF8; // ����
	BarcodeFormat format = BarcodeFormatFromString("Code93"); //��ʽ������
	// ���������е�����
	std::string input = "barcodes";
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
	// ����һ��ҳ��
	HPDF_Page newPage = pdf.getNewPage();
	// ����ҳ������
	HPDF_Page_SetFontAndSize(newPage, pdf.getCnSFont("SimSun"), 20);
	// ��������
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.title"), HPDF_Page_GetHeight(newPage) - 20);
	pdf.drawTextCenter(ZH_WORDS_GETTER("pdf.content"));
	pdf.drawTextCenterH(ZH_WORDS_GETTER("pdf.foot"), 20);
	// ���浽�ļ�
	pdf.saveDocToFile("test-text.pdf");
}

bool BarcodesPdf::barcodesTpl(oatpp::List<SampleBarcodesViewDTO::Wrapper> ldto,string filename)
{
	
	// ���Ի���
	string content ;
	PdfComponent pdf;
	// ����һ��ҳ��
	HPDF_Page newPage = pdf.getNewPage();
	// ����ҳ������
	HPDF_Page_SetFontAndSize(newPage, pdf.getCnSFont("SimSun"), 20);
	// ��������
	for (int i = 1; i <= ldto->size(); i++) {
		content = ldto[i-1]->person_name + "-" + ldto[i-1]->sex + "-" + std::to_string(ldto[i-1]->age) + "-" + ldto[i-1]->barcode + "-" + ldto[i-1]->group_item_name;
		pdf.drawTextCenterH(content, HPDF_Page_GetHeight(newPage)-i*20);
		addBarCodeToPdf(&pdf, ldto[i-1]->barcode, i);
		content.clear();
	}
	// ���浽�ļ�
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
	// ���Ի���
	string content;
	PdfComponent pdf;
	// ����һ��ҳ��
	HPDF_Page newPage = pdf.getNewPage();
	// ����ҳ������
	HPDF_Page_SetFontAndSize(newPage, pdf.getCnSFont("SimSun"), 20);
	// ��������
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

	// ���浽�ļ�
	if (!pdf.saveDocToFile(filename))
	{
		return false;
	}
	else {
		return true;
	}
}
