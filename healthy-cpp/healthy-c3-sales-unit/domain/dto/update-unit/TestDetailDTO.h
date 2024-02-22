#pragma once
#ifndef _TESTDETAILDTO_H_
#define _TESTDETAILDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class TestDetailDTO : public oatpp::DTO
{
	DTO_INIT(TestDetailDTO, DTO);
	//�����Ϣid
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("test.field.id"));
	//��λid
	API_DTO_FIELD_DEFAULT(String, unitId, ZH_WORDS_GETTER("test.field.unit_id"));
	//ְҵ�к����ر���
	API_DTO_FIELD_DEFAULT(String, hazardFactors, ZH_WORDS_GETTER("test.field.hazard_factors"));
	//ְҵ�к���������
	API_DTO_FIELD_DEFAULT(String, hazardFactorsText, ZH_WORDS_GETTER("test.field.hazard_factors_text"));
	//�����к���������
	API_DTO_FIELD_DEFAULT(String, otherHazardFactors, ZH_WORDS_GETTER("test.field.other_hazard_factors"));
	//�ڸ�״̬����
	API_DTO_FIELD_DEFAULT(String, workStateCode, ZH_WORDS_GETTER("test.field.work_state_code"));
	//�ڸ�״̬
	API_DTO_FIELD_DEFAULT(String, workStateText, ZH_WORDS_GETTER("test.field.work_state_text"));
	//���ִ���
	API_DTO_FIELD_DEFAULT(String, workTypeCode, ZH_WORDS_GETTER("test.field.work_type_code"));
	//��������
	API_DTO_FIELD_DEFAULT(String, workTypeText, ZH_WORDS_GETTER("test.field.work_type_text"));
	//������������
	API_DTO_FIELD_DEFAULT(String, workName, ZH_WORDS_GETTER("test.field.work_name"));
	//Ũ�ȣ�ǿ�ȣ���Χ
	API_DTO_FIELD_DEFAULT(String, strength, ZH_WORDS_GETTER("test.field.strength"));
	//���ʱ��
	API_DTO_FIELD_DEFAULT(String, testTime, ZH_WORDS_GETTER("test.field.test_time"));

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TESTDETAILDTO_H_