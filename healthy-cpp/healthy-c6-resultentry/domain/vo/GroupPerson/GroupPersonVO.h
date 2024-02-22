#pragma once
#ifndef _GROUP_PERSON_VO_
#define _GROUP_PERSON_VO_

#include "../../GlobalInclude.h"
#include "../../dto/GroupPerson/GroupPersonDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class GroupPersonJsonVO : public JsonVO<GroupPersonDTO::Wrapper> {
	DTO_INIT(GroupPersonJsonVO, JsonVO<GroupPersonDTO::Wrapper>);
};

// ∑÷“≥’π æ
class GroupPersonPageJsonVO : public JsonVO<GroupPersonPageDTO::Wrapper> {
	DTO_INIT(GroupPersonPageJsonVO, JsonVO<GroupPersonPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GROUP_PERSON_VO_