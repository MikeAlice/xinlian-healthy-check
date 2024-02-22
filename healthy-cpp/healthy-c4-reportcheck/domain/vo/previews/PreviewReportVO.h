#pragma once
#pragma once
#ifndef _PREVIEWREPORTVO_H_
#define _PREVIEWREPORTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/previews/PreviewReportDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/*
* ����Ԥ����ʾJsonVOʵ��
* ������ Z
*/
class PreviewReportJsonVO : public JsonVO<PreviewReportDTO::Wrapper> {
	DTO_INIT(PreviewReportJsonVO, JsonVO<PreviewReportDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PREVIEWREPORTVO_H_
