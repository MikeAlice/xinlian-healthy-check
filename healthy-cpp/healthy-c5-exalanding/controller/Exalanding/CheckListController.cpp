#include "stdafx.h"
#include "CheckListController.h"
#include "../../service/Exalanding/CheckListService.h"
#include "../ApiDeclarativeServicesHelper.h"


CheckListPageJsonVO::Wrapper CheckListController::execQueryCheckList(const CheckListQuery::Wrapper& query)
{
	// 定义一个Service
	CheckListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CheckListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}