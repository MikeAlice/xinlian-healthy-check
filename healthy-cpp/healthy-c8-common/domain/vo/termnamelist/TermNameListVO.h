#pragma once
#ifndef _TermNameListVO_
#define _TermNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/termnamelist/TermNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class TermNameListVO : public JsonVO<TermNameListDTO::Wrapper> {
	DTO_INIT(TermNameListVO, JsonVO<TermNameListDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class TermNameListPageJsonVO : public JsonVO<TermNameListPageDTO::Wrapper> {
	DTO_INIT(TermNameListPageJsonVO, JsonVO<TermNameListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_