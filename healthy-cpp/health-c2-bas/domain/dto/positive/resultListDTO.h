#ifndef _RESULTLISTDTO_H_
#define _RESULTLISTDTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���Խ�������б������ݶ���ʵ��
 */
class resultListDTO : public oatpp::DTO
{
	DTO_INIT(resultListDTO, DTO);
	// ���
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("positive.result.field.id");
	}
	// ����
	DTO_FIELD(String, condition);
	DTO_FIELD_INFO(condition) {
		info->description = ZH_WORDS_GETTER("positive.result.field.condition");
	}
	// �ʺ��Ա�
	DTO_FIELD(String, genderAppropriate);
	DTO_FIELD_INFO(genderAppropriate) {
		info->description = ZH_WORDS_GETTER("positive.result.field.genderAppropriate");
	}
	// ����id
	DTO_FIELD(String, positiveId);
	DTO_FIELD_INFO(positiveId) {
		info->description = ZH_WORDS_GETTER("positive.result.field.positiveId");
	}
	// ����
	DTO_FIELD(String, projectName);
	DTO_FIELD_INFO(projectName) {
		info->description = ZH_WORDS_GETTER("positive.result.field.projectName");
	}
	// �ж�����
	DTO_FIELD(String, judgmentCondition);
	DTO_FIELD_INFO(judgmentCondition) {
		info->description = ZH_WORDS_GETTER("positive.result.field.judgmentCondition");
	}
	// �ų����Խ��
	DTO_FIELD(String, excludePositive);
	DTO_FIELD_INFO(excludePositive) {
		info->description = ZH_WORDS_GETTER("positive.result.field.excludePositive");
	}
	// ����
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("positive.result.field.type");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RESULTLISTDTO_H_