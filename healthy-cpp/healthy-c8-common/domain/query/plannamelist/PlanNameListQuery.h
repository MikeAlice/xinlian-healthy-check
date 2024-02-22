#pragma once
#ifndef _PlanNameListQuery_
#define _PlanNameListQuery_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class PlanNameListQuery : public PageQuery
{
	DTO_INIT(PlanNameListQuery, PageQuery);
	// 套餐名称关键字
	API_DTO_FIELD(String, keyword, ZH_WORDS_GETTER("plannamelist.field.keyword"), false, "");
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_