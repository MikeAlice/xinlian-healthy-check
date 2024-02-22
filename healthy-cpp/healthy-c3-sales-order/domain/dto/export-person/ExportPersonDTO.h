#pragma once

#ifndef _ORDEROUTPUT_DTO_
#define _ORDEROUTPUT_DTO_
#include"../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class ExportPersonDTO :public oatpp::DTO {
	DTO_INIT(ExportPersonDTO,DTO);
	//����
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("person.field.id"));
	//��Ա����
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("person.field.person_name"));
	//�Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("person.field.sex"));
	//֤������
	API_DTO_FIELD_DEFAULT(String, idCard, ZH_WORDS_GETTER("person.field.id_card"));
	//����
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("person.field.age"));
	//����
	API_DTO_FIELD_DEFAULT(String, groupName, ZH_WORDS_GETTER("person.field.group_name"));
	//�ֻ�����
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("person.field.mobile"));
	//����Σ����������
	API_DTO_FIELD_DEFAULT(String, otherHazardFactors, ZH_WORDS_GETTER("person.field.other_hazard_factors"));
	//��������
	API_DTO_FIELD_DEFAULT(String, workTypeText, ZH_WORDS_GETTER("person.field.work_type_text"));
	//������������
	API_DTO_FIELD_DEFAULT(String, workName, ZH_WORDS_GETTER("person.field.work_name"));
	//�ڸ�״̬
	API_DTO_FIELD_DEFAULT(String, workStateText, ZH_WORDS_GETTER("person.field.work_state_text"));
	//��������
	API_DTO_FIELD_DEFAULT(String, department, ZH_WORDS_GETTER("person.field.department"));
	//�������
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("person.field.physical_type"));
	//�Ƿ�ͨ�����(0-δ�Ǽ�, 1-�Ǽ�, 2-�ڼ�, 3-�ܼ�, 4-�����)
	API_DTO_FIELD_DEFAULT(Int32, isPass, ZH_WORDS_GETTER("person.field.is_pass"));
};

#include OATPP_CODEGEN_END(DTO)
#endif