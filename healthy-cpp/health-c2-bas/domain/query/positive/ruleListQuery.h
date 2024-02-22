#ifndef _RULELIST_QUERY_
#define _RULELIST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �����б��ѯ����
 */
class ruleListQuery : public PageQuery
{
	DTO_INIT(ruleListQuery, PageQuery);
	// id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("positive.rules.field.id");
	}
	// ��Ŀ����
	DTO_FIELD(String, projectName);
	DTO_FIELD_INFO(projectName) {
		info->description = ZH_WORDS_GETTER("positive.rules.field.projectName");
	}
	// ����
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("positive.rules.field.type");
	}
	// ����ֵ
	DTO_FIELD(String, regularValue);
	DTO_FIELD_INFO(regularValue) {
		info->description = ZH_WORDS_GETTER("positive.rules.field.regularValue");
	}
	// ���Թ���id
	DTO_FIELD(String, positiveResultsId);
	DTO_FIELD_INFO(positiveResultsId) {
		info->description = ZH_WORDS_GETTER("positive.rules.field.positiveResultsId");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RULELIST_QUERY_