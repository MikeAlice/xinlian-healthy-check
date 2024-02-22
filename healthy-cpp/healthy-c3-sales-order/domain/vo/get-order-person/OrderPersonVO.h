#pragma once

#ifndef _ORDERPERSONVO_H_
#define _ORDERPERSONVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/get-order-person/OrderPersonDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 单位列表显示JsonVO实体
*/
class OrderPersonListJsonVO : public JsonVO<OrderPersonListDTO::Wrapper>
{
	DTO_INIT(OrderPersonListJsonVO, JsonVO<OrderPersonListDTO::Wrapper>);
};

/*
* 单位列表显示分页JsonVO实体
*/
class OrderPersonListPageJsonVO : public JsonVO<OrderPersonListPageDTO::Wrapper>
{
	DTO_INIT(OrderPersonListPageJsonVO, JsonVO<OrderPersonListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_BEGIN(DTO)

#endif // !_ORDERPERSONVO_H_

