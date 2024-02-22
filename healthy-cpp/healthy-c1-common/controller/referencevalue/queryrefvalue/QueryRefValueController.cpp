#include "stdafx.h"
#include "QueryRefValueController.h"
#include "service/referencevalue/queryrefvalue/QueryRefValueService.h"

// 获取数据列表（分页+条件） 负责人：超能
RefValuePageJsonVO::Wrapper QueryRefValueController::execQueryRefValue(const RefValuePageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个service
	QueryRefValueService service;
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = RefValuePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}