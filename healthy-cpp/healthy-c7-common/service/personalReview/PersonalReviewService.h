#pragma once

#ifndef _PERSONALREVIEW_SERVICE_
#define _PERSONALREVIEW_SERVICE_

#include "domain/dto/personalReview/PersonalReviewDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class PersonalReviewService
{
public:

	// �޸����� statu = 1 �����ѹ���
	bool updateData(const PersonalReviewDTO::Wrapper& dto);

};

#endif // !_SAMPLE_SERVICE_

