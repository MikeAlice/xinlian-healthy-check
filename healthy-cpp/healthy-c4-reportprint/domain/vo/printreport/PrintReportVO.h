#pragma once

#ifndef _PRINTREPORT_VO_
#define _PRINTREPORT_VO_

#include "../../GlobalInclude.h"
#include "../../dto/printreport/PrintReportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PrintReportJsonVO : public JsonVO<PrintReportDTO::Wrapper> {
	DTO_INIT(PrintReportJsonVO, JsonVO<PrintReportDTO::Wrapper>);
};

class PrintReportPageJsonVO : public JsonVO<PrintReportPageDTO::Wrapper> {
	DTO_INIT(PrintReportPageJsonVO, JsonVO<PrintReportPageDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_PRINTREPORTS_VO_