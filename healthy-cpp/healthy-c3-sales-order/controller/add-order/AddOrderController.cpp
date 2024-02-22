#include "AddOrderController.h"

StringJsonVO::Wrapper AddOrderController::execAddOrder(const OrderDetailDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();

	jvo->success(dto->id);

	// 响应结果
	return jvo;
}
