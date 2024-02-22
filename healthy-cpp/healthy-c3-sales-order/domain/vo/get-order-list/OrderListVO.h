#pragma once

#ifndef _ORDERLISTVO_H_
#define _ORDERLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/get-order-list/OrderListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/*
订单列表显示Json实体
*/
class OrderListJsonVO : public JsonVO < OrderListDTO::Wrapper > 
{
	DTO_INIT(OrderListJsonVO, JsonVO < OrderListDTO::Wrapper >);
};


/*
* 订单列表显示分页Json实体
*/
class OrderListPageJsonVO :public JsonVO<OrderListPageDTO::Wrapper>
{
	DTO_INIT(OrderListPageJsonVO, JsonVO < OrderListPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_ORDERLISTVO_H_

