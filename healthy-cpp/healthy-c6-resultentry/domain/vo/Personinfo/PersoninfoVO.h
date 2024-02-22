#pragma once
#ifndef _PERSONINFO_VO_
#define _PERSONINFO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/Personinfo/PersoninfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class PersoninfoJsonVO : public JsonVO<PersoninfoDTO::Wrapper> {
	DTO_INIT(PersoninfoJsonVO, JsonVO<PersoninfoDTO::Wrapper>);
};

// ∑÷“≥’π æ
class PersoninfoPageJsonVO : public JsonVO<PersoninfoPageDTO::Wrapper> {
	DTO_INIT(PersoninfoPageJsonVO, JsonVO<PersoninfoPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PERSONINFO_VO_