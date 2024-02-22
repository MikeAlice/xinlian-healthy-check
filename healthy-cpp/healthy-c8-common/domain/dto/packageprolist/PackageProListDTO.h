#pragma once
#ifndef _PackageProListDTO_
#define _PackageProListDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class PackageProListDTO : public oatpp::DTO
{
	DTO_INIT(PackageProListDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, packagepro_name, ZH_WORDS_GETTER("packageprolist.field.packagepro_name"));
};

/**
 * 示例分页传输对象
 */
class PackageProListPageDTO : public PageDTO<PackageProListDTO::Wrapper>
{
	DTO_INIT(PackageProListPageDTO, PageDTO<PackageProListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 