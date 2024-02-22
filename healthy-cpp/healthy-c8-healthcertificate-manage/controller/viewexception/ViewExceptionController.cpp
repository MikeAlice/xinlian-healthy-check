#include "stdafx.h"
#include "ViewExceptionController.h"
#include "../../service/viewexception/ViewExceptionService.h"

ViewExceptionJsonVO::Wrapper ViewExceptionController::execViewException(const ViewExceptionQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	ViewExceptionService service;
	// 查询数据
	auto result = service.getData(query);
	// 响应结果
	auto jvo = ViewExceptionJsonVO::createShared();
	jvo->success(result);
	return jvo;
}