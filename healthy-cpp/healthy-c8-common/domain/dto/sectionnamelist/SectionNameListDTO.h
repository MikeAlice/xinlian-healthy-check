#pragma once
#ifndef _SectionNameListDTO_
#define _SectionNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class SectionNameListDTO : public oatpp::DTO
{
	DTO_INIT(SectionNameListDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, section_name, ZH_WORDS_GETTER("sectionnamelist.field.section_name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif 