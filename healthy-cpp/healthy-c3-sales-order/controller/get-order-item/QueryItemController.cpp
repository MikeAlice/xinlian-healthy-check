#include "QueryItemController.h"

/**
 * ��ȡ���������Ŀ��Ϣ    �����ˣ�Adam
 */
OrderItemJsonVO::Wrapper QueryItemController::execQueryItem(const OrderItemQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ��Ӧ���
	auto jvo = OrderItemJsonVO::createShared();
	
	return jvo;
}
