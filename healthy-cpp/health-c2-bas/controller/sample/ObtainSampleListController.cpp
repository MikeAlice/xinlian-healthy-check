#include "stdafx.h"
#include "ObtainSampleListController.h"
#include "../../service/sample/ObtainSampleListService.h"
#include "../ApiDeclarativeServicesHelper.h"

ObtainSampleListPageJsonVO::Wrapper ObtainSampleListController::execQuerySample(const ObtainSampleListQuery::Wrapper& query)
{
	// 定义一个Service
	ObtainSampleListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ObtainSampleListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

