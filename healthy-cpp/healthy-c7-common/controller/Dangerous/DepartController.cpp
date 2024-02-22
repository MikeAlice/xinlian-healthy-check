#include "stdafx.h"
#include "DepartController.h"
#include "../../service/Dangerous/DepartListService.h"
#include "../ApiDeclarativeServicesHelper.h"

DepartListPageJsonVO::Wrapper DepartController::execQueryDepart(const DepartQuery::Wrapper& query)
{

	// ����һ��Service
	DepartListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = DepartListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	
	//return DepartListPageJsonVO::Wrapper();
}
