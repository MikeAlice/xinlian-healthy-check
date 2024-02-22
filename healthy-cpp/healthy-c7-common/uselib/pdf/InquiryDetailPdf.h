#pragma once
#include "domain/do/evalue/InquiryDetailDO.h"
#ifndef _INQUIRYDETAILPDF_H_
#define _INQUIRYDETAILPDF_H_
/**
 * PDF组件
 */
class InquiryDetailPdf
{
public:
	// 模板绘制
	static void InquiryDetailText(const InquiryDetailDO& Do);
	//static void InquiryDetailTpl(const InquiryDetailDO& Do);
};	


#endif // !_INQUIRYDETAILPDF_H_