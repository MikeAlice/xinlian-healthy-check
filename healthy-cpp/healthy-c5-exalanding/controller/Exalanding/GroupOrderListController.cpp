#include "GroupOrderListController.h"
#include"service/Exalanding/GroupOrderListService.h"
GroupOrderListPageJsonVO::Wrapper GroupOrderListController::execQueryGroupOrder(const GroupOrderListQuery::Wrapper& query, const PayloadDTO& payload)
{
	///定义service
	GroupOrderListService service;
	////查询
	auto result = service.listAll(query);
	////响应结果
	auto jvo = GroupOrderListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	
}
