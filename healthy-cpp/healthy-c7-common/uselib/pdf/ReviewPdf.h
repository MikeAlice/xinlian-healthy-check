#pragma once
#ifndef _REVIEWPDF_H_
#define _REVIEWPDF_H_
#include "domain/do/review/ReviewDO.h"

/**
 * PDF���
 */
class ReviewPdf
{
public:
	// ģ�����
	static void reviewText(const ReviewDO& Do);
	static void reviewTpl(const ReviewDO& Do);
};

#endif // !_REVIEWPDF_H_