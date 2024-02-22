#include"stdafx.h"
#include"service/statisticalmessage/StatisticalMessageService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "StatisticalMessageController.h"




StatisticalMessagePageJsonVO::Wrapper StatisticalMessageController::execQueryStatisticalMessage(const StatisticalMessageQuery::Wrapper& query)
{
	StatisticalMessageService  service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = StatisticalMessagePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
