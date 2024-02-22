#pragma once
#ifndef _UNIT_PEOPLE_VO_
#define _UNIT_PEOPLE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/unitpeople/UnitPeopleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ż���Ա��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class UnitPeopleJsonVO : public JsonVO<UnitPeopleDTO::Wrapper> {
	DTO_INIT(UnitPeopleJsonVO, JsonVO<UnitPeopleDTO::Wrapper>);
};

/**
 * �ż���Ա��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class UnitPeoplePageJsonVO : public JsonVO<UnitPeoplePageDTO::Wrapper> {
	DTO_INIT(UnitPeoplePageJsonVO, JsonVO<UnitPeoplePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNIT_PEOPLE_VO_