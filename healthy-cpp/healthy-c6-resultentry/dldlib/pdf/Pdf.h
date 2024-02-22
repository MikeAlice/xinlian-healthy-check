#pragma once

#ifndef _PDF_H_
#define _PDF_H_
#include"domain/dto/samplebarcodesview/SampleBarcodesViewDTO.h"
#include"domain/dto/reportpreview/ReportPreviewDTO.h"
/**
 * PDF组件测试使用
 */
class BarcodesPdf
{
public:
	// 测试绘制文本
	static void barcodesText();
	// 样本条码绘制
	static bool barcodesTpl(oatpp::List<SampleBarcodesViewDTO::Wrapper> ldto,string filename);
	//报告预览绘制
	static bool reportTpl(oatpp::List<ReportPreviewViewDTO::Wrapper> rpdto,oatpp::List<T_symptomDTO::Wrapper> tsdto, string filename);
};

#endif // !_TESTPDF_H_