#include "stdafx.h"
#include "PersonalReviewController.h"
#include "../../service/personalReview/PersonalReviewService.h"
#include "../ApiDeclarativeServicesHelper.h"

// StringJsonVO
StringJsonVO::Wrapper PersonalReviewController::execUpdatePersonalReview(const PersonalReviewDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();

	// ����һ��Service
	PersonalReviewService service;
	// ִ�������޸�
	if (service.updateData(dto)) {
		jvo->success(dto->personId);
	}
	else
	{
		 jvo->fail(dto->personId);
	}
	// ��Ӧ���
	return jvo;
}


  



 