#include "stdafx.h"
#include "UnitListController.h"
#include "../../service/unitreportlist/UnitPhysicalExaminationOrdersService.h"
#include "../ApiDeclarativeServicesHelper.h"
UnitListPageJsonVO::Wrapper UnitListController::execQueryUnit(const UnitPhysicalExaminationOrdersQuery::Wrapper& query)
{
	//定义一个Service
	UnitPhysicalExaminationOrdersService service;
	//查询数据
	auto result = service.listAll(query);
	//响应结果
	auto jvo = UnitListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
