#pragma once
#ifndef _PREVIEWREPORT_PDF_H_
#define _PREVIEWREPORT_PDF_H_
#include "domain/do/previewreport/PreviewReportDO.h"
/**
 * PDF���
 * �����ˣ�С��
 */
class PreviewReportPdf
{
public:
	// ģ�����
	static void PreviewText(const PreviewReportDO & Do);
};

#endif // !_PREVIEWREPORT_PDF_H_