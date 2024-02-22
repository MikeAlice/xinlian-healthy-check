#include "stdafx.h"
#include "PeopleListController.h"
#include "../../service/Exalanding/PeopleListService.h"
#include "../ApiDeclarativeServicesHelper.h"

PeopleListPageJsonVO::Wrapper PeopleListController::execQueryPeopleList(const PeopleListQuery::Wrapper& query)
{
	// ����һ��Service
	PeopleListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = PeopleListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
