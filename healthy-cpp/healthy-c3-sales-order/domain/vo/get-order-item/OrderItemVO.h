#pragma once

#ifndef _ORDER_ITEM_VO_
#define _ORDER_ITEM_VO_

#include "../../GlobalInclude.h"
#include "../../dto/get-order-item/OrderItemDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ��ȡ���������Ŀ��Ϣ    �����ˣ�Adam
* ��ʾxx��JsonVO��������Ӧ���ͻ��˵�Json����
*/
class OrderItemJsonVO : public JsonVO<OrderItemDTO::Wrapper> {
	DTO_INIT(OrderItemJsonVO, JsonVO<OrderItemDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_ORDER_ITEM_VO_