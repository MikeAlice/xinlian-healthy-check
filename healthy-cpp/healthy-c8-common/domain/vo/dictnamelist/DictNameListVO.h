#pragma once
#ifndef _DictNameListVO_
#define _DictNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/dictnamelist/DictNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class DictNameListJsonVO : public JsonVO<DictNameListDTO::Wrapper> {
	DTO_INIT(DictNameListJsonVO, JsonVO<DictNameListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_