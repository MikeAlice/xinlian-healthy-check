#pragma once
#ifndef _REPORTVO_H_
#define _REPORTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/checks/CheckReportListDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 报告列表显示JsonVO实体
* 负责人 Z
*/
class CheckReportListJsonVO : public JsonVO<CheckReportListDTO::Wrapper> {
	DTO_INIT(CheckReportListJsonVO, JsonVO<CheckReportListDTO::Wrapper>);
};
/*
* 报告列表显示分页JsonVO实体
*/
class CheckReportListPageJsonVO : public JsonVO<CheckReportListPageDTO::Wrapper> {
	DTO_INIT(CheckReportListPageJsonVO, JsonVO<CheckReportListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_REPORTVO_H_
