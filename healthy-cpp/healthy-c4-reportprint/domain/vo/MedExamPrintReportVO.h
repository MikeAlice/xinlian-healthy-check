#pragma once
#ifndef _MEDEXAMPRINTREPORT_VO_
#define _MEDEXAMPRINTREPORT_VO_

#include "../GlobalInclude.h"
#include "../dto/MedExamPrintReportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 单位列表显示JsonVO实体
 * 负责人：小智
 */
class MedExamPrintReportJsonVO : public JsonVO<MedExamPrintReportDTO::Wrapper> {
	DTO_INIT(MedExamPrintReportJsonVO, JsonVO<MedExamPrintReportDTO::Wrapper>);
};

/**
 * 单位分页列表显示JsonVO实体
 * 负责人：小智
 */

class MedExamPrintReportPageJsonVO : public JsonVO<MedExamPrintReportPageDTO::Wrapper> {
	DTO_INIT(MedExamPrintReportPageJsonVO, JsonVO<MedExamPrintReportPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MEDEXAMPRINTREPORT_VO_