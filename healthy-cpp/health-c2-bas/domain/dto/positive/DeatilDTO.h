#ifndef  __DEATIL_DTO__
#define __DEATIL_DTO__
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���Խ���������ʵ��
 */
class DeatilDTO : public oatpp::DTO
{
	DTO_INIT(DeatilDTO, DTO);
	// ���
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("deatil.field.id)");
	}
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("deatil.field.name");
	}
	// ��ƴ
	DTO_FIELD(String, namePinyin);
	DTO_FIELD_INFO(namePinyin) {
		info->description = ZH_WORDS_GETTER("deatil.field.namePinyin");
	}
	// �Ƿ�����
	DTO_FIELD(String, degree);
	DTO_FIELD_INFO(degree) {
		info->description = ZH_WORDS_GETTER("deatil.field.degree");
	}
	//�Ƿ�����
	DTO_FIELD(String, positive);
	DTO_FIELD_INFO(positive) {
		info->description = ZH_WORDS_GETTER("deatil.field.positive");
	}
	//����
	DTO_FIELD(String, sectionName);
	DTO_FIELD_INFO(sectionName) {
		info->description = ZH_WORDS_GETTER("deatil.field.sectionName");
	}
	//ְҵ����
	DTO_FIELD(String, advise);
	DTO_FIELD_INFO(advise) {
		info->description = ZH_WORDS_GETTER("deatil.field.advise");
	}
	//��������
	DTO_FIELD(String, healthKnowledge);
	DTO_FIELD_INFO(healthKnowledge) {
		info->description = ZH_WORDS_GETTER("deatili.field.healthKnowledge");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !__DEATIL_DTO__#pragma once
