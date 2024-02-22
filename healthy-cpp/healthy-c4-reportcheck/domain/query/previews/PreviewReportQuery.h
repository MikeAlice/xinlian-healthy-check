#pragma once
#ifndef _PREVIEWREPORT_H_
#define _PREVIEWREPORT_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 报告审核的报告预览
* 负责人 Z
*/

class PreviewReportQuery : public PageQuery {
	DTO_INIT(PreviewReportQuery, PageQuery);
	
	// 人员的id
	API_DTO_FIELD_DEFAULT(String, persionId, ZH_WORDS_GETTER("preview.field.persionid"));

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_PREVIEWREPORT_H_
