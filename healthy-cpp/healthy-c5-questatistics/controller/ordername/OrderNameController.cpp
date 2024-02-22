
#include "stdafx.h"
#include "OrderNameController.h"
#include "../../service/ordername/OrderNameService.h"
#include "../ApiDeclarativeServicesHelper.h"

OrderNamePageJsonVO::Wrapper OrderNameController::execQueryOrderName(const OrderNameQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	OrderNameService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = OrderNamePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return OrderNamePageJsonVO::Wrapper();
}
