#include "stdafx.h"
#include "DepartController.h"
#include "../../service/Dangerous/DepartListService.h"
#include "../ApiDeclarativeServicesHelper.h"

DepartListPageJsonVO::Wrapper DepartController::execQueryDepart(const DepartQuery::Wrapper& query)
{

	// 定义一个Service
	DepartListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = DepartListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	
	//return DepartListPageJsonVO::Wrapper();
}
