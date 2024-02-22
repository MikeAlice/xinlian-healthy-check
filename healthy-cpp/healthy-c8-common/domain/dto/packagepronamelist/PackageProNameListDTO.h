#pragma once
#ifndef _PackageProNameListDTO_
#define _PackageProNameListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class PackageProNameListDTO : public oatpp::DTO
{
	DTO_INIT(PackageProNameListDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, packagepro_name, ZH_WORDS_GETTER("packagepronamelist.field.packagepro_name"));
};


#include OATPP_CODEGEN_END(DTO)
#endif 