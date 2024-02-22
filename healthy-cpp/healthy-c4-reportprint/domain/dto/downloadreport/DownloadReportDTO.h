#pragma once

#ifndef _DOWNLOADREPORT_H_
#define _DOWNLOADREPORT_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 信息传输数据对象
 */
class DownloadReportDTO : public oatpp::DTO
{
	DTO_INIT(DownloadReportDTO, DTO);
	// 报告src
	API_DTO_FIELD(String, url, ZH_WORDS_GETTER("preview.field.report-url"), true, {});
	// 报告文字描述
	API_DTO_FIELD_DEFAULT(String, alt, ZH_WORDS_GETTER("preview.field.report-alt"));
	// 报告链接地址
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("preview.field.href"));
public:
	DownloadReportDTO() {}
	DownloadReportDTO(String url, String alt = "", String href = "")
	{
		this->url = url;
		this->alt = alt;
		this->href = href;
	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DOWNLOADREPORT_H_