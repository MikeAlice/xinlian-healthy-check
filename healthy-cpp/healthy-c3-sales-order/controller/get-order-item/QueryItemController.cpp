#include "QueryItemController.h"

/**
 * 获取订单体检项目信息    负责人：Adam
 */
OrderItemJsonVO::Wrapper QueryItemController::execQueryItem(const OrderItemQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 响应结果
	auto jvo = OrderItemJsonVO::createShared();
	
	return jvo;
}
