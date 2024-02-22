#include "stdafx.h"
#include "CheckListController.h"
#include "../../service/Exalanding/CheckListService.h"
#include "../ApiDeclarativeServicesHelper.h"


CheckListPageJsonVO::Wrapper CheckListController::execQueryCheckList(const CheckListQuery::Wrapper& query)
{
	// ����һ��Service
	CheckListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CheckListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}