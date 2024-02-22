#pragma once
#ifndef _COUNTCHECK_VO
#define _COUNTCHECK_VO

#include "../../GlobalInclude.h"
#include "../../dto/check/CountCheckDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class CountCheckJsonVO : public JsonVO<CountCheckDTO::Wrapper> {
	DTO_INIT(CountCheckJsonVO, JsonVO<CountCheckDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_