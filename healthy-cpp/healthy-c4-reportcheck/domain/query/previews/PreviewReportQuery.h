#pragma once
#ifndef _PREVIEWREPORT_H_
#define _PREVIEWREPORT_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* ������˵ı���Ԥ��
* ������ Z
*/

class PreviewReportQuery : public PageQuery {
	DTO_INIT(PreviewReportQuery, PageQuery);
	
	// ��Ա��id
	API_DTO_FIELD_DEFAULT(String, persionId, ZH_WORDS_GETTER("preview.field.persionid"));

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_PREVIEWREPORT_H_
