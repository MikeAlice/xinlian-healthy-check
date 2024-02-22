#pragma once

#ifndef _MODIFYORDERCONTROLLER_H_
#define _MODIFYORDERCONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/dto/get-order-detail/OrderDetailDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 修改订单    负责人：jimyy
 */
class ModifyOrderController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ModifyOrderController);
public: // 3 定义接口
// 	// 3.1 定义接口描述
// 	// 3.2 定义接口处理
	
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("order.put.summary"), modifyOrder, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/sales/order/update", modifyOrder, BODY_DTO(OrderDetailDTO::Wrapper, dto), execModifyOrder(dto, authObject->getPayload()));

private: // 3.3 定义接口执行函数
	StringJsonVO::Wrapper execModifyOrder(const OrderDetailDTO::Wrapper& dto, const PayloadDTO& payload);

};

#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // !_MODIFYORDERCONTROLLER_H_
