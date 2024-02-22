#pragma once
#ifndef _PERSONINFO_DTO_
#define _PERSONINFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PersoninfoDTO : public oatpp::DTO
{
	DTO_INIT(PersoninfoDTO, DTO);
	// 姓名
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("group_person.data.name");
	}
	// 性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("group_person.data.sex");
	}
	// 年龄
	DTO_FIELD(UInt32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("group_person.data.age");
	}
	// 体检类型
	DTO_FIELD(String, physical_type);
	DTO_FIELD_INFO(physical_type) {
		info->description = ZH_WORDS_GETTER("group_person.data.physical_type");
	}
	// 是否零星体检
	DTO_FIELD(UInt32, sporadic_physical);
	DTO_FIELD_INFO(sporadic_physical) {
		info->description = ZH_WORDS_GETTER("geoup_person.data.sporadic_physical");
	}
};

class PersoninfoPageDTO : public PageDTO<PersoninfoDTO::Wrapper>
{
	DTO_INIT(PersoninfoPageDTO, PageDTO<PersoninfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PERSONINFO_DTO_