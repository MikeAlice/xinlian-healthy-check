#include "stdafx.h"
#include "NameListController.h"
#include <service/contract/NameListService.h>
#include <service/contract/BaseInfoService.h>

NameListPageJsonVO::Wrapper NameListController::execQueryNameList(const NameListQuery::Wrapper& query)
{
	// 定义一个Service
	NameListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = NameListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

BaseInfoJsonVO::Wrapper NameListController::execQueryBaseInfo(const BaseInfoQuery::Wrapper& query)
{
	// 定义一个Service
	BaseInfoService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = BaseInfoPageJsonVO::createShared();
	jvo->success(result);
	//return jvo;
	return {};
}


