#pragma once
#ifndef _ReportReviewDTO_
#define _ReportReviewDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������˴������
 */
class ReportReviewDTO : public oatpp::DTO
{
	DTO_INIT(ReportReviewDTO, DTO);
	// �����
	DTO_FIELD(String, testNum);
	DTO_FIELD_INFO(testNum) {
		info->description = ZH_WORDS_GETTER("reportreview.field.testNum");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // 