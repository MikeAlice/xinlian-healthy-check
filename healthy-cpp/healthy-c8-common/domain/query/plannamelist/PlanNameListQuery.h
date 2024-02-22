#pragma once
#ifndef _PlanNameListQuery_
#define _PlanNameListQuery_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class PlanNameListQuery : public PageQuery
{
	DTO_INIT(PlanNameListQuery, PageQuery);
	// �ײ����ƹؼ���
	API_DTO_FIELD(String, keyword, ZH_WORDS_GETTER("plannamelist.field.keyword"), false, "");
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_