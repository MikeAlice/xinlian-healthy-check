#pragma once
#ifndef _GROUP_PERSON_INFO_VO_
#define _GROUP_PERSON_INFO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/GroupPersonInfo/GroupPersonInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��Ա������ʾJsonVOʵ��
 */
class GroupPersonInfoJsonVO : public JsonVO<GroupPersonInfoDTO::Wrapper> {
	DTO_INIT(GroupPersonInfoJsonVO, JsonVO<GroupPersonInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_GROUP_PERSON_INFO_VO_