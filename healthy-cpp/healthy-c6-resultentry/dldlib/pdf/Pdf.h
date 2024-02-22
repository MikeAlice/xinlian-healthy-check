#pragma once

#ifndef _PDF_H_
#define _PDF_H_
#include"domain/dto/samplebarcodesview/SampleBarcodesViewDTO.h"
#include"domain/dto/reportpreview/ReportPreviewDTO.h"
/**
 * PDF�������ʹ��
 */
class BarcodesPdf
{
public:
	// ���Ի����ı�
	static void barcodesText();
	// �����������
	static bool barcodesTpl(oatpp::List<SampleBarcodesViewDTO::Wrapper> ldto,string filename);
	//����Ԥ������
	static bool reportTpl(oatpp::List<ReportPreviewViewDTO::Wrapper> rpdto,oatpp::List<T_symptomDTO::Wrapper> tsdto, string filename);
};

#endif // !_TESTPDF_H_