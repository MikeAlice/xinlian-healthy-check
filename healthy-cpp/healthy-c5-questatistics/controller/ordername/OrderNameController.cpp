
#include "stdafx.h"
#include "OrderNameController.h"
#include "../../service/ordername/OrderNameService.h"
#include "../ApiDeclarativeServicesHelper.h"

OrderNamePageJsonVO::Wrapper OrderNameController::execQueryOrderName(const OrderNameQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	OrderNameService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = OrderNamePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
	//return OrderNamePageJsonVO::Wrapper();
}
