#pragma once

#ifndef _STATISTICALMESSAGEVO_
#define _STATISTICALMESSAGEVO_

#include "../../GlobalInclude.h"
#include "../../dto/statisticalmessage/StatisticalMessageDTO.h"
#include "../../query/statisticalmessage/StatisticalMessageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 单位列表显示JsonVO实体
 */
class StatisticalMessageVO : public JsonVO<StatisticalMessageDTO::Wrapper> {
	DTO_INIT(StatisticalMessageVO, JsonVO<StatisticalMessageDTO::Wrapper>);
};

/**
 * 单位列表显示分页JsonVO实体
 */
class StatisticalMessagePageJsonVO : public JsonVO<StatisticalMessagePageDTO::Wrapper> {
	DTO_INIT(StatisticalMessagePageJsonVO, JsonVO<StatisticalMessagePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_