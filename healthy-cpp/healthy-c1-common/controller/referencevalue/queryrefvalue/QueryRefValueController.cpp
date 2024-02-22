#include "stdafx.h"
#include "QueryRefValueController.h"
#include "service/referencevalue/queryrefvalue/QueryRefValueService.h"

// ��ȡ�����б���ҳ+������ �����ˣ�����
RefValuePageJsonVO::Wrapper QueryRefValueController::execQueryRefValue(const RefValuePageQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��service
	QueryRefValueService service;
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = RefValuePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}