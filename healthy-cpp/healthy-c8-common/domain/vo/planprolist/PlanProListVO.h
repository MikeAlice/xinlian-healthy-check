#pragma once
#ifndef _PlanProListVO_
#define _PlanProListVO_

#include "../../GlobalInclude.h"
#include "../../dto/planprolist/PlanProListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ʾJsonVO��������Ӧ���ͻ��˵�Json����
 */
class PlanProListJsonVO : public JsonVO<PlanProListDTO::Wrapper> {
	DTO_INIT(PlanProListJsonVO, JsonVO<PlanProListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_