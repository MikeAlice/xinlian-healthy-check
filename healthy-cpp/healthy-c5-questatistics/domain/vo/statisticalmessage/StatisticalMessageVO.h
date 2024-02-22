#pragma once

#ifndef _STATISTICALMESSAGEVO_
#define _STATISTICALMESSAGEVO_

#include "../../GlobalInclude.h"
#include "../../dto/statisticalmessage/StatisticalMessageDTO.h"
#include "../../query/statisticalmessage/StatisticalMessageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ�б���ʾJsonVOʵ��
 */
class StatisticalMessageVO : public JsonVO<StatisticalMessageDTO::Wrapper> {
	DTO_INIT(StatisticalMessageVO, JsonVO<StatisticalMessageDTO::Wrapper>);
};

/**
 * ��λ�б���ʾ��ҳJsonVOʵ��
 */
class StatisticalMessagePageJsonVO : public JsonVO<StatisticalMessagePageDTO::Wrapper> {
	DTO_INIT(StatisticalMessagePageJsonVO, JsonVO<StatisticalMessagePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_