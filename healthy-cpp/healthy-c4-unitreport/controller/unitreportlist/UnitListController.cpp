#include "stdafx.h"
#include "UnitListController.h"
#include "../../service/unitreportlist/UnitPhysicalExaminationOrdersService.h"
#include "../ApiDeclarativeServicesHelper.h"
UnitListPageJsonVO::Wrapper UnitListController::execQueryUnit(const UnitPhysicalExaminationOrdersQuery::Wrapper& query)
{
	//����һ��Service
	UnitPhysicalExaminationOrdersService service;
	//��ѯ����
	auto result = service.listAll(query);
	//��Ӧ���
	auto jvo = UnitListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
