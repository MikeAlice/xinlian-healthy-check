#include"stdafx.h"
#include"service/statisticalmessage/StatisticalMessageService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "StatisticalMessageController.h"




StatisticalMessagePageJsonVO::Wrapper StatisticalMessageController::execQueryStatisticalMessage(const StatisticalMessageQuery::Wrapper& query)
{
	StatisticalMessageService  service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = StatisticalMessagePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
