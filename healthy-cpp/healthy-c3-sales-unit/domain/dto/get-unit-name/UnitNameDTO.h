#pragma once

#ifndef _UNITNAMEDTO_H_
#define _UNITNAMEDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取单位名称列表（用于输入表单下拉列表框）    负责人：Tutu糊涂涂
 */

class UnitNameDTO : public oatpp::DTO
{
	DTO_INIT(UnitNameDTO, DTO);
	//单位ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("unit.field.id"));
	//单位名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unit.field.name"));
};

class UnitNamePageDTO : public PageDTO<UnitNameDTO::Wrapper> {
	DTO_INIT(UnitNamePageDTO, PageDTO<UnitNameDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITNAMEDTO_H_
