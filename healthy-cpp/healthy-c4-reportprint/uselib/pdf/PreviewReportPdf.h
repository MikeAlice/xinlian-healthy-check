#pragma once
#ifndef _PREVIEWREPORT_PDF_H_
#define _PREVIEWREPORT_PDF_H_
#include "domain/do/previewreport/PreviewReportDO.h"
/**
 * PDF组件
 * 负责人：小智
 */
class PreviewReportPdf
{
public:
	// 模板绘制
	static void PreviewText(const PreviewReportDO & Do);
};

#endif // !_PREVIEWREPORT_PDF_H_