#include "stdafx.h"
#include "GroupPersonController.h"

GroupPersonPageJsonVO::Wrapper GroupPersonController::execQueryByGroupPerson(const GroupPersonQuery::Wrapper& gpq)
{
	// 定义一个Service
	GroupPersonService service;
	// 查询数据
	auto result = service.listAll(gpq);
	// 响应结果
	auto jvo = GroupPersonPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}