#pragma once

#ifndef _GROUPDETAILVO_H_
#define _GROUPDETAILVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/get-order-detail/GroupDetailDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)


class GroupDetailVO : public JsonVO<GroupDetailDTO::Wrapper>
{
	DTO_INIT(GroupDetailVO, JsonVO<GroupDetailDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUPDETAILVO_H_
