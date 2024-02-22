#pragma once
#ifndef _PlanNameListVO_
#define _PlanNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/plannamelist/PlanNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class PlanNameListVO : public JsonVO<PlanNameListDTO::Wrapper> {
	DTO_INIT(PlanNameListVO, JsonVO<PlanNameListDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class PlanNameListPageJsonVO : public JsonVO<PlanNameListPageDTO::Wrapper> {
	DTO_INIT(PlanNameListPageJsonVO, JsonVO<PlanNameListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_