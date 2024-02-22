#pragma once

#ifndef _ORDERDETAILVO_H_
#define _ORDERDETAILVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/get-order-detail/OrderDetailDTO.h"
#include "GroupDetailVO.h"
#include OATPP_CODEGEN_BEGIN(DTO)


class OrderDetailJsonVO : public JsonVO<OrderDetailDTO::Wrapper>
{
	DTO_INIT(OrderDetailJsonVO, JsonVO<OrderDetailDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_ORDERDETAILVO_H_

