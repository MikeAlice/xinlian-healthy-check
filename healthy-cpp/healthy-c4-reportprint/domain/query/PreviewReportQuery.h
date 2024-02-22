#pragma once
#ifndef _PREVIEWREPORT_H_
#define _PREVIEWREPORT_H_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 报告打印报告预览
 * 负责人：小智
 */
class PreviewReportQuery : public PageQuery
{
	DTO_INIT(PreviewReportQuery, PageQuery);

	// 体检人员编号
	API_DTO_FIELD_DEFAULT(String, personId, ZH_WORDS_GETTER("preview.field.personId"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PREVIEWREPORT_H_
