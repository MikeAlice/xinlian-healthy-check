#pragma once
#ifndef _MEDEXAMPRINTREPORT_VO_
#define _MEDEXAMPRINTREPORT_VO_

#include "../GlobalInclude.h"
#include "../dto/MedExamPrintReportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ�б���ʾJsonVOʵ��
 * �����ˣ�С��
 */
class MedExamPrintReportJsonVO : public JsonVO<MedExamPrintReportDTO::Wrapper> {
	DTO_INIT(MedExamPrintReportJsonVO, JsonVO<MedExamPrintReportDTO::Wrapper>);
};

/**
 * ��λ��ҳ�б���ʾJsonVOʵ��
 * �����ˣ�С��
 */

class MedExamPrintReportPageJsonVO : public JsonVO<MedExamPrintReportPageDTO::Wrapper> {
	DTO_INIT(MedExamPrintReportPageJsonVO, JsonVO<MedExamPrintReportPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MEDEXAMPRINTREPORT_VO_