#pragma once

#ifndef _ORDERPERSONVO_H_
#define _ORDERPERSONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/get-order-person/OrderPersonDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* ��λ�б���ʾJsonVOʵ��
*/
class OrderPersonListJsonVO : public JsonVO<OrderPersonListDTO::Wrapper>
{
	DTO_INIT(OrderPersonListJsonVO, JsonVO<OrderPersonListDTO::Wrapper>);
};

/*
* ��λ�б���ʾ��ҳJsonVOʵ��
*/
class OrderPersonListPageJsonVO : public JsonVO<OrderPersonListPageDTO::Wrapper>
{
	DTO_INIT(OrderPersonListPageJsonVO, JsonVO<OrderPersonListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_BEGIN(DTO)

#endif // !_ORDERPERSONVO_H_

