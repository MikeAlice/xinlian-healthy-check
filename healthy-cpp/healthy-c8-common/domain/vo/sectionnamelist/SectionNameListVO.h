#pragma once
#ifndef _SectionNameListVO_
#define _SectionNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/sectionnamelist/SectionNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class SectionNameListJsonVO : public JsonVO<SectionNameListDTO::Wrapper> {
	DTO_INIT(SectionNameListJsonVO, JsonVO<SectionNameListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_