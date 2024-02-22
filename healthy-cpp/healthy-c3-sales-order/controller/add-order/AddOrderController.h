#pragma once
#ifndef _ADDORDERCONTROLLER_H_
#define _ADDORDERCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/get-order-detail/OrderDetailDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class AddOrderController : public oatpp::web::server::api::ApiController
{
	//定义控制器访问入口
	API_ACCESS_DECLARE(AddOrderController);

public://定义接口
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("order.post.summary"), addOrder, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/sales/order/add", addOrder, BODY_DTO(OrderDetailDTO::Wrapper, dto), execAddOrder(dto, authObject->getPayload()));

private://定义接口执行函数
	StringJsonVO::Wrapper execAddOrder(const OrderDetailDTO::Wrapper& dto, const PayloadDTO& payload);
};



#include OATPP_CODEGEN_BEGIN(ApiController)

#endif // !_ADDORDERCONTROLLER_H_
