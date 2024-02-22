#pragma once
#ifndef _REVIEWPDF_H_
#define _REVIEWPDF_H_
#include "domain/do/review/ReviewDO.h"

/**
 * PDF组件
 */
class ReviewPdf
{
public:
	// 模板绘制
	static void reviewText(const ReviewDO& Do);
	static void reviewTpl(const ReviewDO& Do);
};

#endif // !_REVIEWPDF_H_