#pragma once
#ifndef _ReportReviewDTO_
#define _ReportReviewDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 报告审核传输对象
 */
class ReportReviewDTO : public oatpp::DTO
{
	DTO_INIT(ReportReviewDTO, DTO);
	// 体检编号
	DTO_FIELD(String, testNum);
	DTO_FIELD_INFO(testNum) {
		info->description = ZH_WORDS_GETTER("reportreview.field.testNum");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // 