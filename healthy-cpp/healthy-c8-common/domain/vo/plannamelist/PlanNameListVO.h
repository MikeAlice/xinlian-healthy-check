#pragma once
#ifndef _PlanNameListVO_
#define _PlanNameListVO_

#include "../../GlobalInclude.h"
#include "../../dto/plannamelist/PlanNameListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PlanNameListVO : public JsonVO<PlanNameListDTO::Wrapper> {
	DTO_INIT(PlanNameListVO, JsonVO<PlanNameListDTO::Wrapper>);
};

/**
 * ʾ����ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PlanNameListPageJsonVO : public JsonVO<PlanNameListPageDTO::Wrapper> {
	DTO_INIT(PlanNameListPageJsonVO, JsonVO<PlanNameListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_