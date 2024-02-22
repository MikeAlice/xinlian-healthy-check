#ifndef _RESULTLISTDTO_H_
#define _RESULTLISTDTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 阳性结果规则列表传输数据对象实体
 */
class resultListDTO : public oatpp::DTO
{
	DTO_INIT(resultListDTO, DTO);
	// 编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("positive.result.field.id");
	}
	// 条件
	DTO_FIELD(String, condition);
	DTO_FIELD_INFO(condition) {
		info->description = ZH_WORDS_GETTER("positive.result.field.condition");
	}
	// 适合性别
	DTO_FIELD(String, genderAppropriate);
	DTO_FIELD_INFO(genderAppropriate) {
		info->description = ZH_WORDS_GETTER("positive.result.field.genderAppropriate");
	}
	// 阳性id
	DTO_FIELD(String, positiveId);
	DTO_FIELD_INFO(positiveId) {
		info->description = ZH_WORDS_GETTER("positive.result.field.positiveId");
	}
	// 规则
	DTO_FIELD(String, projectName);
	DTO_FIELD_INFO(projectName) {
		info->description = ZH_WORDS_GETTER("positive.result.field.projectName");
	}
	// 判断条件
	DTO_FIELD(String, judgmentCondition);
	DTO_FIELD_INFO(judgmentCondition) {
		info->description = ZH_WORDS_GETTER("positive.result.field.judgmentCondition");
	}
	// 排除阳性结果
	DTO_FIELD(String, excludePositive);
	DTO_FIELD_INFO(excludePositive) {
		info->description = ZH_WORDS_GETTER("positive.result.field.excludePositive");
	}
	// 类型
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("positive.result.field.type");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RESULTLISTDTO_H_