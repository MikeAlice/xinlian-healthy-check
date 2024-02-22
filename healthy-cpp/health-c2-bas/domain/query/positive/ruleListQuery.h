#ifndef _RULELIST_QUERY_
#define _RULELIST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 规则列表查询对象
 */
class ruleListQuery : public PageQuery
{
	DTO_INIT(ruleListQuery, PageQuery);
	// id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("positive.rules.field.id");
	}
	// 项目名称
	DTO_FIELD(String, projectName);
	DTO_FIELD_INFO(projectName) {
		info->description = ZH_WORDS_GETTER("positive.rules.field.projectName");
	}
	// 类型
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("positive.rules.field.type");
	}
	// 规则值
	DTO_FIELD(String, regularValue);
	DTO_FIELD_INFO(regularValue) {
		info->description = ZH_WORDS_GETTER("positive.rules.field.regularValue");
	}
	// 阳性规则id
	DTO_FIELD(String, positiveResultsId);
	DTO_FIELD_INFO(positiveResultsId) {
		info->description = ZH_WORDS_GETTER("positive.rules.field.positiveResultsId");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RULELIST_QUERY_