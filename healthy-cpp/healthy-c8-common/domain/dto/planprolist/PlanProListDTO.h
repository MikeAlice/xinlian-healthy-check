#pragma once
#ifndef _PlanProListDTO_
#define _PlanProListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class PlanProListDTO : public oatpp::DTO
{
	DTO_INIT(PlanProListDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, planpro_name, ZH_WORDS_GETTER("planprolist.field.planpro_name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif 