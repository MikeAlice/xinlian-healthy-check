#pragma once
#ifndef _INTERRO_DTO_
#define _INTERRO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* 症状询问传输对象
*/
class InterroDTO : public oatpp::DTO {
	DTO_INIT(InterroDTO, DTO);
	// 主键
	// DTO_FIELD(String, id);
	// DTO_FIELD_INFO(id) {
	// 	info->description = ZH_WORDS_GETTER("interro2.field.id");
	// }
	// 类别
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type) {
		info->description = ZH_WORDS_GETTER("interro2.field.type");
	}
	// 体检项目
	DTO_FIELD(String, project);
	DTO_FIELD_INFO(project) {
		info->description = ZH_WORDS_GETTER("interro2.field.project");
	}
	// 项目编号
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("interro2.field.code");
	}
	// 危机程度
	DTO_FIELD(String, degree);
	DTO_FIELD_INFO(degree) {
		info->description = ZH_WORDS_GETTER("interro2.field.degree");
	}
	// 病程时间
	DTO_FIELD(String, coursetime);
	DTO_FIELD_INFO(coursetime) {
		info->description = ZH_WORDS_GETTER("interro2.field.coursetime");
	}
	// 人员编号主键
	DTO_FIELD(String, personid);
	DTO_FIELD_INFO(personid) {
		info->description = ZH_WORDS_GETTER("interro2.field.personid");
	}
	// 创建人-体检医生
	DTO_FIELD(String, createid);
	DTO_FIELD_INFO(createid) {
		info->description = ZH_WORDS_GETTER("interro2.field.createid");
	}
	//检查医生
	DTO_FIELD(String, createname);
	DTO_FIELD_INFO(createname) {
		info->description = ZH_WORDS_GETTER("interro2.field.createname");
	}
	// 创建时间
	//DTO_FIELD(String, createtime);
	//DTO_FIELD_INFO(createtime) {
	//	info->description = ZH_WORDS_GETTER("interro2.field.createtime");
	//}
};

#include OATPP_CODEGEN_END(DTO)
#endif // _INTERRO_DTO_
