#pragma once
#include "domain/do/evalue/InquiryDetailDO.h"
#ifndef _INQUIRYDETAILPDF_H_
#define _INQUIRYDETAILPDF_H_
/**
 * PDF���
 */
class InquiryDetailPdf
{
public:
	// ģ�����
	static void InquiryDetailText(const InquiryDetailDO& Do);
	//static void InquiryDetailTpl(const InquiryDetailDO& Do);
};	


#endif // !_INQUIRYDETAILPDF_H_