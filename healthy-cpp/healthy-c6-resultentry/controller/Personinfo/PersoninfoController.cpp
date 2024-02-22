#include "stdafx.h"
#include "PersoninfoController.h"

PersoninfoPageJsonVO::Wrapper PersoninfoController::execQueryByPersoninfo(const PersoninfoQuery::Wrapper& gpq)
{
	// 定义一个Service
	PersoninfoService service;
	// 查询数据
	auto result = service.listAll(gpq);
	// 响应结果
	auto jvo = PersoninfoPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}