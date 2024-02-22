#pragma once

#ifndef _INSERTSAMPLE_VO_
#define _INSERTSAMPLE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/sample/InsertSampleDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示JsonVO，用于响应给客户端的Json对象
 */
class InsertSampleJsonVO : public JsonVO<InsertSampleDTO::Wrapper> {
	DTO_INIT(InsertSampleJsonVO, JsonVO<InsertSampleDTO::Wrapper>);
};

/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class InsertSamplePageJsonVO : public JsonVO<InsertSamplePageDTO::Wrapper> {
	DTO_INIT(InsertSamplePageJsonVO, JsonVO<InsertSamplePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_INSERTSAMPLE_VO_