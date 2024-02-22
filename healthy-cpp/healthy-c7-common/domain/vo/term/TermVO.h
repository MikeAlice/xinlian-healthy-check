#pragma once
#ifndef _TERMVO_H_
#define _TERMVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/term/TermListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ��λ�б���ʾJsonVOʵ��
 */
class TermListJsonVO : public JsonVO<TermListDTO::Wrapper>
{
	DTO_INIT(TermListJsonVO, JsonVO<TermListDTO::Wrapper>);
};
/**
 * ��λ�б���ʾ��ҳJsonVOʵ��
 */
class TermListPageJsonVO : public JsonVO<TermListPageDTO::Wrapper> {
	DTO_INIT(TermListPageJsonVO, JsonVO<TermListPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif