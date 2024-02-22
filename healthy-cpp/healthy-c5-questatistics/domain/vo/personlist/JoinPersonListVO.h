#pragma once

#ifndef _JOINPERSONLISTVO_
#define _JOINPERSONLISTVO_

#include "../../GlobalInclude.h"
#include "../../dto/personlist/JoinPersonListDTO.h"
#include "../../query/personlist/JoinPersonListQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ�б���ʾJsonVOʵ��
 */
class JoinPersonListJsonVO : public JsonVO<JoinPersonListDTO::Wrapper> {
	DTO_INIT(JoinPersonListJsonVO, JsonVO<JoinPersonListDTO::Wrapper>);
};

/**
 * ��λ�б���ʾ��ҳJsonVOʵ��
 */
class PersonListPageJsonVO : public JsonVO<PersonListPageDTO::Wrapper> {
	DTO_INIT(PersonListPageJsonVO, JsonVO<PersonListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_