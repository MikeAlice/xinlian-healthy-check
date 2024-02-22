#pragma once
#ifndef _PREVIEWREPORTDTO_H_
#define _PREVIEWREPORTDTO_H_
#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ�б����ݴ������ʵ��
 * �����ˣ�С��
 */
class PreviewReportDTO : public oatpp::DTO
{
	DTO_INIT(PreviewReportDTO, DTO);
	// PDF��ַ
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("preview.field.href"));
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_PREVIEWREPORTDTO_H_