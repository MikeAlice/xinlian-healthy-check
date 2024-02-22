#pragma once
#ifndef _PlanNameListDTO_
#define _PlanNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class PlanNameListDTO : public oatpp::DTO
{
	DTO_INIT(PlanNameListDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, plan_name, ZH_WORDS_GETTER("plannamelist.field.plan_name"));
};
/**
 * 示例分页传输对象
 */
class PlanNameListPageDTO : public PageDTO<PlanNameListDTO::Wrapper>
{
	DTO_INIT(PlanNameListPageDTO, PageDTO<PlanNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 