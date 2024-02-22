#pragma once

#ifndef _DOWNLOADREPORTVO_H_
#define _DOWNLOADREPORTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/downloadreport/downloadReportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * PDF上传结果数据
 */
class DownloadReportVO : public JsonVO<DownloadReportDTO::Wrapper>
{
	DTO_INIT(DownloadReportVO, JsonVO<DownloadReportDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DOWNLOADREPORTVO_H_