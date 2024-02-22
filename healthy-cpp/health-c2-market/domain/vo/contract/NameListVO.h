#pragma once
#ifndef _NAMELIST_VO_
#define _NAMELIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/contract/NameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class NameListJsonVO : public JsonVO<NameListDTO::Wrapper> {
	DTO_INIT(NameListJsonVO, JsonVO<NameListDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class NameListPageJsonVO : public JsonVO<NameListPageDTO::Wrapper> {
	DTO_INIT(NameListPageJsonVO, JsonVO<NameListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_