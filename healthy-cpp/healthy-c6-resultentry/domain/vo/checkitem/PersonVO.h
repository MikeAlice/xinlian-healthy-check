#pragma once
#ifndef _PERSONVO_H_
#define _PERSONVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/checkitem/PersonDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/*
*��λ�б���ʾJsonVOʵ��
*/
class PersonJsonVO : public JsonVO<PersonDTO::Wrapper> {
	DTO_INIT(PersonJsonVO, JsonVO<PersonDTO::Wrapper>);

};

class PersonPageJsonVO : public JsonVO<PersonPageDTO::Wrapper> {
	DTO_INIT(PersonPageJsonVO, JsonVO<PersonPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PERSONVO_H_
