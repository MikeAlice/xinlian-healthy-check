#include "stdafx.h"
#include "../../domain/vo/check/CountCheckVo.h"
#include "CountCheckController.h"
#include "../../service/check/CountCheckService.h"

CountCheckJsonVO::Wrapper CountCheckController::execQueryCountCheck(const CountCheckQuery::Wrapper& query)
{
	// 定义一个Service
	CountCheckService service;
	// 查询数据
	auto result = service.countAll(query);
	// 响应结果
	auto jvo = CountCheckJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

