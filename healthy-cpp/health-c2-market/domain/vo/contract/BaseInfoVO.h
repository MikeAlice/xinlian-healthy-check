#pragma once
#ifndef _BASEINFO_VO_
#define _BASEINFO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/contract/BaseInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class BaseInfoJsonVO : public JsonVO<BaseInfoDTO::Wrapper> {
	DTO_INIT(BaseInfoJsonVO, JsonVO<BaseInfoDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class BaseInfoPageJsonVO : public JsonVO<BaseInfoPageDTO::Wrapper> {
	DTO_INIT(BaseInfoPageJsonVO, JsonVO<BaseInfoPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_