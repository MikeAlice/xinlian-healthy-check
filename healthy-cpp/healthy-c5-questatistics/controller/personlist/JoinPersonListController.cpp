#include"stdafx.h"
#include"JoinPersonListController.h"
#include"service/personlist/JoinPersonListService.h"
#include "../ApiDeclarativeServicesHelper.h"


PersonListPageJsonVO::Wrapper JoinPersonListController:: execQueryPersonList(const JoinPersonListQuery::Wrapper& query)
{
	JoinPersonListService  service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = PersonListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return {};
}
