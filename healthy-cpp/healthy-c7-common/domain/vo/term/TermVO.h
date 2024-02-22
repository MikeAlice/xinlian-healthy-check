#pragma once
#ifndef _TERMVO_H_
#define _TERMVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/term/TermListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 单位列表显示JsonVO实体
 */
class TermListJsonVO : public JsonVO<TermListDTO::Wrapper>
{
	DTO_INIT(TermListJsonVO, JsonVO<TermListDTO::Wrapper>);
};
/**
 * 单位列表显示分页JsonVO实体
 */
class TermListPageJsonVO : public JsonVO<TermListPageDTO::Wrapper> {
	DTO_INIT(TermListPageJsonVO, JsonVO<TermListPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif