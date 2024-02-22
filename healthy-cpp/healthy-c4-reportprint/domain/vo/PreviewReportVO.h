#pragma once
#ifndef _PREVIEWREPORT_VO_
#define _PREVIEWREPORT_VO_

#include "../GlobalInclude.h"
#include "../dto/PreviewReportDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 单位列表显示JsonVO实体
 * 负责人：小智
 */
class PreviewReportJsonVO : public JsonVO<PreviewReportDTO::Wrapper> {
	DTO_INIT(PreviewReportJsonVO, JsonVO<PreviewReportDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PREVIEWREPORT_VO_