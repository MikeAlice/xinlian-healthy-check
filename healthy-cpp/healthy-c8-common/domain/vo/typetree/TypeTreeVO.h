#pragma once
#ifndef _TypeTreeVO_
#define _TypeTreeVO_

#include "../../GlobalInclude.h"
#include "../../dto/typetree/TypeTreeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class TypeTreeJsonVO : public JsonVO<TypeTreeDTO::Wrapper> {
	DTO_INIT(TypeTreeJsonVO, JsonVO<TypeTreeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_