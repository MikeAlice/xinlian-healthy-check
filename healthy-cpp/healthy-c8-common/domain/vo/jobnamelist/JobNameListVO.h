#pragma once
#ifndef _JobNameListVO_
#define _JobNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/jobnamelist/JobNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class JobNameListJsonVO : public JsonVO<JobNameListDTO::Wrapper> {
	DTO_INIT(JobNameListJsonVO, JsonVO<JobNameListDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class JobNameListPageJsonVO : public JsonVO<JobNameListPageDTO::Wrapper> {
	DTO_INIT(JobNameListPageJsonVO, JsonVO<JobNameListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_