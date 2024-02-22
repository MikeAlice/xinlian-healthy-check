#pragma once

#ifndef _JOINPERSONLISTVO_
#define _JOINPERSONLISTVO_

#include "../../GlobalInclude.h"
#include "../../dto/personlist/JoinPersonListDTO.h"
#include "../../query/personlist/JoinPersonListQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 单位列表显示JsonVO实体
 */
class JoinPersonListJsonVO : public JsonVO<JoinPersonListDTO::Wrapper> {
	DTO_INIT(JoinPersonListJsonVO, JsonVO<JoinPersonListDTO::Wrapper>);
};

/**
 * 单位列表显示分页JsonVO实体
 */
class PersonListPageJsonVO : public JsonVO<PersonListPageDTO::Wrapper> {
	DTO_INIT(PersonListPageJsonVO, JsonVO<PersonListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_