#ifndef _RULELIST_DTO_
#define _RULELIST_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 规则传输数据对象实体
 */
class ruleListDTO : public oatpp::DTO
{
	DTO_INIT(ruleListDTO, DTO);
	// 唯一编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("positive.rules.field.id"));
	// 项目名称
	API_DTO_FIELD_DEFAULT(String, projectName, ZH_WORDS_GETTER("positive.rules.field.projectName"));
	// 类型
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("positive.rules.field.type"));
	//规则值
	API_DTO_FIELD_DEFAULT(String, regularValue, ZH_WORDS_GETTER("positive.rules.field.regularValue"));
	// 阳性规则Id
	API_DTO_FIELD_DEFAULT(String, positiveResultsId, ZH_WORDS_GETTER("positive.rules.field.positiveResultsId"));
};

/**
 * 分页传输对象
 */
class rulePageDTO : public PageDTO<ruleListDTO::Wrapper>
{
	DTO_INIT(rulePageDTO, PageDTO<ruleListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RULELIST_DTO_