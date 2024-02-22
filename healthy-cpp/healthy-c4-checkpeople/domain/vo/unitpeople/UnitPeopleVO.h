#pragma once
#ifndef _UNIT_PEOPLE_VO_
#define _UNIT_PEOPLE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/unitpeople/UnitPeopleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 团检人员显示JsonVO，用于响应给客户端的Json对象
 */
class UnitPeopleJsonVO : public JsonVO<UnitPeopleDTO::Wrapper> {
	DTO_INIT(UnitPeopleJsonVO, JsonVO<UnitPeopleDTO::Wrapper>);
};

/**
 * 团检人员分页显示JsonVO，用于响应给客户端的Json对象
 */
class UnitPeoplePageJsonVO : public JsonVO<UnitPeoplePageDTO::Wrapper> {
	DTO_INIT(UnitPeoplePageJsonVO, JsonVO<UnitPeoplePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNIT_PEOPLE_VO_