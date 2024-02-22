#pragma once

#ifndef _REPORTCHECK_DTO_
#define _REPORTCHECK_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 批量下载报告传输对象——千亿
 */
class ReportDownloadDTO : public oatpp::DTO
{
	DTO_INIT(ReportDownloadDTO, DTO);
	// 报告编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("sample.field.id");
	};
};

/**
 * 更新状态传输对象——千亿
 */
class UpdateStatusDTO : public oatpp::DTO
{
	DTO_INIT(UpdateStatusDTO, DTO);
	// 报告编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("reportcheck.field.id");
	}
	// 审核状态
	DTO_FIELD(UInt64, check_status);
	DTO_FIELD_INFO(check_status) {
		info->description = ZH_WORDS_GETTER("reportcheck.update.check_status");
	}
	// 打印状态
	DTO_FIELD(UInt64, print_status);
	DTO_FIELD_INFO(print_status) {
		info->description = ZH_WORDS_GETTER("reportcheck.update.print_status");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_REPORTCHECK_DTO_