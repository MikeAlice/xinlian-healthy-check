#pragma once

#ifndef _UNITNAMEVO_H_
#define _UNITNAMEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/get-unit-name/UnitNameDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取单位名称列表（用于输入表单下拉列表框）    负责人：Tutu糊涂涂
 */
class UnitNameJsonVO : public JsonVO<UnitNameDTO::Wrapper>
{
	DTO_INIT(UnitNameJsonVO, JsonVO<UnitNameDTO::Wrapper>);
};
class UnitNamePageJsonVO : public JsonVO<UnitNamePageDTO::Wrapper> {
	DTO_INIT(UnitNamePageJsonVO, JsonVO<UnitNamePageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITNAMEVO_H_
