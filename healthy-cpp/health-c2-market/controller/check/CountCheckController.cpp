#include "stdafx.h"
#include "../../domain/vo/check/CountCheckVo.h"
#include "CountCheckController.h"
#include "../../service/check/CountCheckService.h"

CountCheckJsonVO::Wrapper CountCheckController::execQueryCountCheck(const CountCheckQuery::Wrapper& query)
{
	// ����һ��Service
	CountCheckService service;
	// ��ѯ����
	auto result = service.countAll(query);
	// ��Ӧ���
	auto jvo = CountCheckJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

