#pragma once
#ifndef _PREVIEWREPORT_H_
#define _PREVIEWREPORT_H_

#include "../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����ӡ����Ԥ��
 * �����ˣ�С��
 */
class PreviewReportQuery : public PageQuery
{
	DTO_INIT(PreviewReportQuery, PageQuery);

	// �����Ա���
	API_DTO_FIELD_DEFAULT(String, personId, ZH_WORDS_GETTER("preview.field.personId"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PREVIEWREPORT_H_
