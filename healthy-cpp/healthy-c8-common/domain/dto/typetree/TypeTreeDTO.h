#pragma once
#ifndef _TypeTreeDTO_
#define _TypeTreeDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class TypeTreeDTO : public oatpp::DTO
{
	DTO_INIT(TypeTreeDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, type_name, ZH_WORDS_GETTER("typetree.field.type_name"));
};
#include OATPP_CODEGEN_END(DTO)
#endif 