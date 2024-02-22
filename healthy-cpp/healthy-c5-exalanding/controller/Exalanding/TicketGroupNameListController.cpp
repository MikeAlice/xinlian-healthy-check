#include "stdafx.h"
#include "TicketGroupNameListController.h"
#include "../../service/Exalanding/TicketGroupNameListService.h"
#include "../ApiDeclarativeServicesHelper.h"

TicketGroupNameListPageJsonVO::Wrapper TicketGroupNameListController::execQueryTicketGroupNameList(const TicketGroupNameListQuery::Wrapper& query)
{
	// ����һ��Service
	TicketGroupNameListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = TicketGroupNameListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
