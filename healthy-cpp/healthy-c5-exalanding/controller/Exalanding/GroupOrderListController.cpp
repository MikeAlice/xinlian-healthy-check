#include "GroupOrderListController.h"
#include"service/Exalanding/GroupOrderListService.h"
GroupOrderListPageJsonVO::Wrapper GroupOrderListController::execQueryGroupOrder(const GroupOrderListQuery::Wrapper& query, const PayloadDTO& payload)
{
	///����service
	GroupOrderListService service;
	////��ѯ
	auto result = service.listAll(query);
	////��Ӧ���
	auto jvo = GroupOrderListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	
}
