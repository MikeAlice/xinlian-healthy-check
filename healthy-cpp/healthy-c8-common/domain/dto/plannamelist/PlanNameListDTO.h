#pragma once
#ifndef _PlanNameListDTO_
#define _PlanNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class PlanNameListDTO : public oatpp::DTO
{
	DTO_INIT(PlanNameListDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, plan_name, ZH_WORDS_GETTER("plannamelist.field.plan_name"));
};
/**
 * ʾ����ҳ�������
 */
class PlanNameListPageDTO : public PageDTO<PlanNameListDTO::Wrapper>
{
	DTO_INIT(PlanNameListPageDTO, PageDTO<PlanNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 