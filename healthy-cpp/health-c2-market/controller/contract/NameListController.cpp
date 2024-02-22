#include "stdafx.h"
#include "NameListController.h"
#include <service/contract/NameListService.h>
#include <service/contract/BaseInfoService.h>

NameListPageJsonVO::Wrapper NameListController::execQueryNameList(const NameListQuery::Wrapper& query)
{
	// ����һ��Service
	NameListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = NameListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

BaseInfoJsonVO::Wrapper NameListController::execQueryBaseInfo(const BaseInfoQuery::Wrapper& query)
{
	// ����һ��Service
	BaseInfoService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = BaseInfoPageJsonVO::createShared();
	jvo->success(result);
	//return jvo;
	return {};
}


