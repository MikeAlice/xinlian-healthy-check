#pragma once
#ifndef _PREVIEWREPORTDTO_H_
#define _PREVIEWREPORTDTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* ��λ�б�����ݴ������ʵ��
* ������ Z
*/

class PreviewReportDTO : public oatpp::DTO {
	DTO_INIT(PreviewReportDTO, DTO);

	// pdf���ص�ַ
	API_DTO_FIELD_DEFAULT(String, pdfaddress, ZH_WORDS_GETTER("preview.field.pdfaddress"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PREVIEWREPORTDTO_H_
