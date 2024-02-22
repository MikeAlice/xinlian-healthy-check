#ifndef _REPORTVO_H_
#define _REPORTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/report/ReportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//单位列表显示JsonVO实体
class ReportJsonVO : public JsonVO<ReportDTO::Wrapper> {
	DTO_INIT(ReportJsonVO, JsonVO<ReportDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 

