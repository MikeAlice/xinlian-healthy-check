#include"stdafx.h"
#include"JoinPersonListController.h"
#include"service/personlist/JoinPersonListService.h"
#include "../ApiDeclarativeServicesHelper.h"


PersonListPageJsonVO::Wrapper JoinPersonListController:: execQueryPersonList(const JoinPersonListQuery::Wrapper& query)
{
	JoinPersonListService  service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = PersonListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return {};
}
