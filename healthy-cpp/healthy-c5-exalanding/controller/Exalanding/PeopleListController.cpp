#include "stdafx.h"
#include "PeopleListController.h"
#include "../../service/Exalanding/PeopleListService.h"
#include "../ApiDeclarativeServicesHelper.h"

PeopleListPageJsonVO::Wrapper PeopleListController::execQueryPeopleList(const PeopleListQuery::Wrapper& query)
{
	// 定义一个Service
	PeopleListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = PeopleListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
