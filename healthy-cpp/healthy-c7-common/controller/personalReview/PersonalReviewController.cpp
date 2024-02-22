#include "stdafx.h"
#include "PersonalReviewController.h"
#include "../../service/personalReview/PersonalReviewService.h"
#include "../ApiDeclarativeServicesHelper.h"

// StringJsonVO
StringJsonVO::Wrapper PersonalReviewController::execUpdatePersonalReview(const PersonalReviewDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();

	// 定义一个Service
	PersonalReviewService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->personId);
	}
	else
	{
		 jvo->fail(dto->personId);
	}
	// 响应结果
	return jvo;
}


  



 