#include "stdafx.h"
#include "ViewExceptionController.h"
#include "../../service/viewexception/ViewExceptionService.h"

ViewExceptionJsonVO::Wrapper ViewExceptionController::execViewException(const ViewExceptionQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	ViewExceptionService service;
	// ��ѯ����
	auto result = service.getData(query);
	// ��Ӧ���
	auto jvo = ViewExceptionJsonVO::createShared();
	jvo->success(result);
	return jvo;
}