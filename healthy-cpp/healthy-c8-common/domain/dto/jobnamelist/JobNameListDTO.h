#pragma once
#ifndef _JobNameListDTO_
#define _JobNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class JobNameListDTO : public oatpp::DTO
{
	DTO_INIT(JobNameListDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, keyword, ZH_WORDS_GETTER("jobnamelist.field.keyword"));
};

/**
 * 示例分页传输对象
 */
class JobNameListPageDTO : public PageDTO<JobNameListDTO::Wrapper>
{
	DTO_INIT(JobNameListPageDTO, PageDTO<JobNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 