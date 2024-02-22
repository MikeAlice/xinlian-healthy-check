#include "stdafx.h"
#include "UnitController.h"
#include "../../service/unitpeople/UnitPeopleService.h"
#include "../ApiDeclarativeServicesHelper.h"

UnitPeoplePageJsonVO::Wrapper UnitController::execQueryUnit(const UnitPeopleQuery::Wrapper& query)
{
	
	//����һ��service
	UnitPeopleService service;
	//��ѯ����
	auto result = service.listAll(query);
	//��Ӧ���
	auto jvo = UnitPeoplePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
