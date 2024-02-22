#pragma once
#ifndef _UNIT_PEOPLE_DTO_
#define _UNIT_PEOPLE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ż���Ա�������
 */
class UnitPeopleDTO : public oatpp::DTO
{
	DTO_INIT(UnitPeopleDTO, DTO);
	//�������Ա�֤�����롢���ա����䡢�Ƿ���䡢�ֻ�����
	DTO_FIELD(String, personName);
	DTO_FIELD_INFO(personName) {
		info->description = ZH_WORDS_GETTER("unit.field.personName");
	}
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("unit.field.sex");
	}
	DTO_FIELD(String, idCard);
	DTO_FIELD_INFO(idCard) {
		info->description = ZH_WORDS_GETTER("unit.field.idCard");
	}
	DTO_FIELD(String, birth);
	DTO_FIELD_INFO(birth) {
		info->description = ZH_WORDS_GETTER("unit.field.birth");
	}
	DTO_FIELD(Int64, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("unit.field.age");
	}
	DTO_FIELD(String, isMarry);
	DTO_FIELD_INFO(isMarry) {
		info->description = ZH_WORDS_GETTER("unit.field.isMarry");
	}
	DTO_FIELD(String, mobile);
	DTO_FIELD_INFO(mobile) {
		info->description = ZH_WORDS_GETTER("unit.field.mobile");
	}
};

/**
 * �ż���Ա��ҳ�������
 */
class UnitPeoplePageDTO : public PageDTO<UnitPeopleDTO::Wrapper>
{
	DTO_INIT(UnitPeoplePageDTO, PageDTO<UnitPeopleDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_UNIT_PEOPLE_DTO_