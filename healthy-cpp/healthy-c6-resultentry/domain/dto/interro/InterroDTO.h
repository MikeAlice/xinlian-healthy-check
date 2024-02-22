#pragma once
#ifndef _INTERRO_DTO_
#define _INTERRO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* ֢״ѯ�ʴ������
*/
class InterroDTO : public oatpp::DTO {
	DTO_INIT(InterroDTO, DTO);
	// ����
	// DTO_FIELD(String, id);
	// DTO_FIELD_INFO(id) {
	// 	info->description = ZH_WORDS_GETTER("interro2.field.id");
	// }
	// ���
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("interro2.field.type");
	}
	// �����Ŀ
	DTO_FIELD(String, project);
	DTO_FIELD_INFO(project) {
		info->description = ZH_WORDS_GETTER("interro2.field.project");
	}
	// ��Ŀ���
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("interro2.field.code");
	}
	// Σ���̶�
	DTO_FIELD(String, degree);
	DTO_FIELD_INFO(degree) {
		info->description = ZH_WORDS_GETTER("interro2.field.degree");
	}
	// ����ʱ��
	DTO_FIELD(String, coursetime);
	DTO_FIELD_INFO(coursetime) {
		info->description = ZH_WORDS_GETTER("interro2.field.coursetime");
	}
	// ��Ա�������
	DTO_FIELD(String, personid);
	DTO_FIELD_INFO(personid) {
		info->description = ZH_WORDS_GETTER("interro2.field.personid");
	}
	// ������-���ҽ��
	DTO_FIELD(String, createid);
	DTO_FIELD_INFO(createid) {
		info->description = ZH_WORDS_GETTER("interro2.field.createid");
	}
	//���ҽ��
	DTO_FIELD(String, createname);
	DTO_FIELD_INFO(createname) {
		info->description = ZH_WORDS_GETTER("interro2.field.createname");
	}
	// ����ʱ��
	//DTO_FIELD(String, createtime);
	//DTO_FIELD_INFO(createtime) {
	//	info->description = ZH_WORDS_GETTER("interro2.field.createtime");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif // _INTERRO_DTO_
