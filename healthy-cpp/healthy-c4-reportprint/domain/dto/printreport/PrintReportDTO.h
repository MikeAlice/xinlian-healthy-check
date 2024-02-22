#pragma once

#ifndef _PRINTREPORTDTO_H_
#define _PRINTREPORTDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
class PrintReportDTO : public oatpp::DTO
{
	DTO_INIT(PrintReportDTO, DTO);
	// 报告id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("preview.field.reportNum");
	}
	// 报告打印次数
	DTO_FIELD(UInt32, report_printing_num);
	DTO_FIELD_INFO(report_printing_num) {
		info->description = ZH_WORDS_GETTER("addition.field.printNum");
	}
	// 打印状态
	DTO_FIELD(UInt32, print_state);
	DTO_FIELD_INFO(print_state) {
		info->description = ZH_WORDS_GETTER("print.field.printState");
	}
};

class PrintReportPageDTO : public PageDTO<PrintReportDTO::Wrapper>
{
	DTO_INIT(PrintReportPageDTO, PageDTO<PrintReportDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PRINTREPORTDTO_H_