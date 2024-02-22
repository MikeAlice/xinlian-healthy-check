#include "stdafx.h"
#include "UnitController.h"
#include "../../service/unitpeople/UnitPeopleService.h"
#include "../ApiDeclarativeServicesHelper.h"

UnitPeoplePageJsonVO::Wrapper UnitController::execQueryUnit(const UnitPeopleQuery::Wrapper& query)
{
	
	//定义一个service
	UnitPeopleService service;
	//查询数据
	auto result = service.listAll(query);
	//响应结果
	auto jvo = UnitPeoplePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
