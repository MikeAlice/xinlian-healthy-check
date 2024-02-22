#pragma once
#ifndef _TermNameListDTO_
#define _TermNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class TermNameListDTO : public oatpp::DTO
{
	DTO_INIT(TermNameListDTO, DTO);
};

/**
 * 示例分页传输对象
 */
class TermNameListPageDTO : public PageDTO<TermNameListDTO::Wrapper>
{
	DTO_INIT(TermNameListPageDTO, PageDTO<TermNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 