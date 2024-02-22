#pragma once
#ifndef _TermNameListQuery_
#define _TermNameListQuery_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class TermNameListQuery : public PageQuery
{
	DTO_INIT(TermNameListQuery, PageQuery);
	// 体检类型
	DTO_FIELD(String, type_inspection);
	DTO_FIELD_INFO(type_inspection) {
		info->description = ZH_WORDS_GETTER("termnamelist.field.type_inspection");
	}
	// 术语类型
	DTO_FIELD(String, type_term);
	DTO_FIELD_INFO(type_term) {
		info->description = ZH_WORDS_GETTER("termnamelist.field.type_term");
	}
	// 危害因素
	DTO_FIELD(String, factor_danger);
	DTO_FIELD_INFO(factor_danger) {
		info->description = ZH_WORDS_GETTER("termnamelist.field.factor_danger");
	}
	// 在岗状态
	DTO_FIELD(String, statu_on);
	DTO_FIELD_INFO(statu_on) {
		info->description = ZH_WORDS_GETTER("termnamelist.field.statu_on");
	}
	// 术语内容
	DTO_FIELD(String, content_term);
	DTO_FIELD_INFO(content_term) {
		info->description = ZH_WORDS_GETTER("termnamelist.field.content_term");
	}
	// 创建时间
	DTO_FIELD(String, create_date);
	DTO_FIELD_INFO(create_date) {
		info->description = ZH_WORDS_GETTER("termnamelist.field.create_date");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_