#include "AddOrderController.h"

StringJsonVO::Wrapper AddOrderController::execAddOrder(const OrderDetailDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// ���巵�����ݶ���
	auto jvo = StringJsonVO::createShared();

	jvo->success(dto->id);

	// ��Ӧ���
	return jvo;
}
