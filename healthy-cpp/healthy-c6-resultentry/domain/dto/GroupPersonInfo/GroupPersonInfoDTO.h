#pragma once
#ifndef _GROUP_PERSON_INFO_DTO_
#define _GROUP_PERSON_INFO_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ��Ա���鴫�����ݶ���ʵ��
 */
class GroupPersonInfoDTO : public oatpp::DTO
{
	DTO_INIT(GroupPersonInfoDTO, DTO);

	//�Ƿ�ͨ�����
	API_DTO_FIELD_DEFAULT(UInt32, is_pass, ZH_WORDS_GETTER("group_person.data.is_pass"));

	// �����
	API_DTO_FIELD_DEFAULT(String, test_num, ZH_WORDS_GETTER("group_person.data.test_num"));

	// ���֤��
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("group_person.data.id_card"));
	
	// ����
	API_DTO_FIELD_DEFAULT(String, person_name, ZH_WORDS_GETTER("group_person.data.name"));

	// �Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("group_person.data.sex"));

	// ����
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("group_person.data.age"));
	
	// �������
	API_DTO_FIELD_DEFAULT(String, physical_type, ZH_WORDS_GETTER("group_person.data.physical_type"));
	
	// ��������
	API_DTO_FIELD_DEFAULT(UInt32, sporadic_physical, ZH_WORDS_GETTER("group_person.data.sporadic_physical"));

	// ��λ����
	API_DTO_FIELD_DEFAULT(String, dept, ZH_WORDS_GETTER("group_person.data.dept"));
	
	// �Ǽ�ʱ��
	API_DTO_FIELD_DEFAULT(String, create_time, ZH_WORDS_GETTER("group_person.data.create_time"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUP_PERSON_INFO_DTO_