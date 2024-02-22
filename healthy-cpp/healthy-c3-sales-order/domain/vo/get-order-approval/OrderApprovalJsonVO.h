#pragma once

#ifndef _ORDERVIEWAPPROVAL_VO
#define _ORDERVIEWAPPROVAL_VO
#include"../../GlobalInclude.h"
#include "../../dto/get-order-approval/OrderApprovalDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)
class OrderApprovalJsonVO :public JsonVO<OrderApprovalDTO::Wrapper>
{
	DTO_INIT(OrderApprovalJsonVO, JsonVO<OrderApprovalDTO::Wrapper>);
};
#include OATPP_CODEGEN_BEGIN(DTO)
#endif