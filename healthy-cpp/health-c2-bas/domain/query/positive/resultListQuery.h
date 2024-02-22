#ifndef _RESULTLISTQUERY_H_
#define _RESULTLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 阳性结果规则列表查询对象
 */
class resultListQuery : public PageQuery
{
	DTO_INIT(resultListQuery, PageQuery);
	// id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("positive.resRules.field.id");
	}
	// 条件
	DTO_FIELD(String, condition);
	DTO_FIELD_INFO(condition) {
		info->description = ZH_WORDS_GETTER("positive.resRules.field.condition");
	}
	// 适合性别
	DTO_FIELD(String, genderAppropriate);
	DTO_FIELD_INFO(genderAppropriate) {
		info->description = ZH_WORDS_GETTER("positive.resRules.field.genderAppropriate");
	}
	// 阳性id
	DTO_FIELD(String, positiveId);
	DTO_FIELD_INFO(positiveId) {
		info->description = ZH_WORDS_GETTER("positive.resRules.field.positiveId");
	}
	// 规则
	DTO_FIELD(String, projectName);
	DTO_FIELD_INFO(projectName) {
		info->description = ZH_WORDS_GETTER("positive.resRules.field.projectName");
	}
	// 判断条件
	DTO_FIELD(String, judgmentCondition);
	DTO_FIELD_INFO(judgmentCondition) {
		info->description = ZH_WORDS_GETTER("positive.resRules.field.judgmentCondition");
	}
	// 排除阳性结果
	DTO_FIELD(String, excludePositive);
	DTO_FIELD_INFO(excludePositive) {
		info->description = ZH_WORDS_GETTER("positive.resRules.field.excludePositive");
	}
	// 类型
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("positive.resRules.field.type");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RESULTLISTQUERY_H_