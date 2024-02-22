#ifndef _REPORTVO_H_
#define _REPORTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/report/ReportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//��λ�б���ʾJsonVOʵ��
class ReportJsonVO : public JsonVO<ReportDTO::Wrapper> {
	DTO_INIT(ReportJsonVO, JsonVO<ReportDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 

