#include"stdafx.h"
#include"GroupPersonInfoController.h"

#include "domain/GlobalInclude.h"
#include "./service/GroupPersonInfo/GroupPersonInfoService.h"

// 实现人员详情查询接口函数
GroupPersonInfoJsonVO::Wrapper GroupPersonInfoController::queryPersonInfo(const GroupPersonInfoQuery::Wrapper& query)
{
	// 定义Service
	GroupPersonInfoService service;
	// 查询数据
	auto result = service.queryInfo(query);
	// 响应结果
	auto jvo = GroupPersonInfoJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
