#pragma once
#ifndef _REPORTVO_H_
#define _REPORTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/checks/CheckReportListDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
* �����б���ʾJsonVOʵ��
* ������ Z
*/
class CheckReportListJsonVO : public JsonVO<CheckReportListDTO::Wrapper> {
	DTO_INIT(CheckReportListJsonVO, JsonVO<CheckReportListDTO::Wrapper>);
};
/*
* �����б���ʾ��ҳJsonVOʵ��
*/
class CheckReportListPageJsonVO : public JsonVO<CheckReportListPageDTO::Wrapper> {
	DTO_INIT(CheckReportListPageJsonVO, JsonVO<CheckReportListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_REPORTVO_H_
