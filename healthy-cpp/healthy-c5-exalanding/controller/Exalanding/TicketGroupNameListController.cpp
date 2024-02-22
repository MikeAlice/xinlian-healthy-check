#include "stdafx.h"
#include "TicketGroupNameListController.h"
#include "../../service/Exalanding/TicketGroupNameListService.h"
#include "../ApiDeclarativeServicesHelper.h"

TicketGroupNameListPageJsonVO::Wrapper TicketGroupNameListController::execQueryTicketGroupNameList(const TicketGroupNameListQuery::Wrapper& query)
{
	// 定义一个Service
	TicketGroupNameListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = TicketGroupNameListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
