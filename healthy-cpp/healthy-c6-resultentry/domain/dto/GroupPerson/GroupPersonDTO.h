#pragma once
#ifndef _GROUP_PERSON_DTO_
#define _GROUP_PERSON_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class GroupPersonDTO : public oatpp::DTO
{
	DTO_INIT(GroupPersonDTO, DTO);
	// ����
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("group_person.data.name");
	}
	// �Ա�
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("group_person.data.sex");
	}
	// ����
	DTO_FIELD(UInt32, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("group_person.data.age");
	}
	// �������
	DTO_FIELD(String, physical_type);
	DTO_FIELD_INFO(physical_type) {
		info->description = ZH_WORDS_GETTER("group_person.data.physical_type");
	}
	// �Ƿ��������
	DTO_FIELD(UInt32, sporadic_physical);
	DTO_FIELD_INFO(sporadic_physical) {
		info->description = ZH_WORDS_GETTER("group_person.data.sporadic_physical");
	}
};

class GroupPersonPageDTO : public PageDTO<GroupPersonDTO::Wrapper>
{
	DTO_INIT(GroupPersonPageDTO, PageDTO<GroupPersonDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUP_PERSON_DTO_