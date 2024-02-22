#pragma once

#ifndef _PERSONALREVIEW_SERVICE_
#define _PERSONALREVIEW_SERVICE_

#include "domain/dto/personalReview/PersonalReviewDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class PersonalReviewService
{
public:

	// 修改数据 statu = 1 设置已过审
	bool updateData(const PersonalReviewDTO::Wrapper& dto);

};

#endif // !_SAMPLE_SERVICE_

