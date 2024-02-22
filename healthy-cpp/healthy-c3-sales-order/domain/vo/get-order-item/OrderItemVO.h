#pragma once

#ifndef _ORDER_ITEM_VO_
#define _ORDER_ITEM_VO_

#include "../../GlobalInclude.h"
#include "../../dto/get-order-item/OrderItemDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 获取订单体检项目信息    负责人：Adam
* 显示xx的JsonVO，用于响应给客户端的Json对象
*/
class OrderItemJsonVO : public JsonVO<OrderItemDTO::Wrapper> {
	DTO_INIT(OrderItemJsonVO, JsonVO<OrderItemDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_ORDER_ITEM_VO_