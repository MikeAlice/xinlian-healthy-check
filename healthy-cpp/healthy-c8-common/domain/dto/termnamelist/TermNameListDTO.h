#pragma once
#ifndef _TermNameListDTO_
#define _TermNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class TermNameListDTO : public oatpp::DTO
{
	DTO_INIT(TermNameListDTO, DTO);
};

/**
 * ʾ����ҳ�������
 */
class TermNameListPageDTO : public PageDTO<TermNameListDTO::Wrapper>
{
	DTO_INIT(TermNameListPageDTO, PageDTO<TermNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 