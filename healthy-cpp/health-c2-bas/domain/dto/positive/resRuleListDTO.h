#ifndef _RESRULELIST_DTO_
#define _RESRULELIST_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 结果规则传输数据对象实体
 */
class resRuleListDTO : public oatpp::DTO
{
	DTO_INIT(resRuleListDTO, DTO);
	// 唯一编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("positive.resRules.field.id"));
	// 条件
	API_DTO_FIELD_DEFAULT(String, condition, ZH_WORDS_GETTER("positive.resRules.field.condition"));
	// 适合性别
	API_DTO_FIELD_DEFAULT(String, genderAppropriate, ZH_WORDS_GETTER("positive.resRules.field.genderAppropriate"));
	//阳性Id
	API_DTO_FIELD_DEFAULT(String, positiveId, ZH_WORDS_GETTER("positive.resRules.field.positiveId"));
	// 规则
	API_DTO_FIELD_DEFAULT(String, projectName, ZH_WORDS_GETTER("positive.resRules.field.projectName"));
	// 判断条件
	API_DTO_FIELD_DEFAULT(String, judgmentCondition, ZH_WORDS_GETTER("positive.resRules.field.judgmentCondition"));
	// 排除阳性结果
	API_DTO_FIELD_DEFAULT(String, excludePositive, ZH_WORDS_GETTER("positive.resRules.field.excludePositive"));
	// 类型
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("positive.resRules.field.type"));
};

/**
 * 分页传输对象
 */
class resRulePageDTO : public PageDTO<resRuleListDTO::Wrapper>
{
	DTO_INIT(resRulePageDTO, PageDTO<resRuleListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_RESRULELIST_DTO_