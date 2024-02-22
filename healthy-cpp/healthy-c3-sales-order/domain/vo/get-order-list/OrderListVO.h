#pragma once

#ifndef _ORDERLISTVO_H_
#define _ORDERLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/get-order-list/OrderListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/*
�����б���ʾJsonʵ��
*/
class OrderListJsonVO : public JsonVO < OrderListDTO::Wrapper > 
{
	DTO_INIT(OrderListJsonVO, JsonVO < OrderListDTO::Wrapper >);
};


/*
* �����б���ʾ��ҳJsonʵ��
*/
class OrderListPageJsonVO :public JsonVO<OrderListPageDTO::Wrapper>
{
	DTO_INIT(OrderListPageJsonVO, JsonVO < OrderListPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_ORDERLISTVO_H_

