#pragma once

#ifndef _SAMPLE_QUERY_
#define _SAMPLE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* ��λ��ҳ��ѯʵ��
*/

class UnitQuery : public PageQuery
{
	DTO_INIT(UnitQuery, PageQuery);
	//��ѯ����
	//API_DTO_FIELD_DEFAULT(UInt32,type, ZH_WORDS_GETTER("evalue.field.type"));
	//�������
	API_DTO_FIELD_DEFAULT(UInt32,ispass, ZH_WORDS_GETTER("getUserName.field.ispass"));
	// ����״̬  ������Ա�ڸ�����Ա��Ϣ���в�ѯ
	API_DTO_FIELD_DEFAULT(UInt32, isRecheck, ZH_WORDS_GETTER("getUserName.field.isRecheck"));
	//��ʼʱ��
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("getUserName.field.startDate"));
	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("getUserName.field.endDate"));
	//����
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("getUserName.field.personName"));
	//�����
	API_DTO_FIELD_DEFAULT(String, testNum, ZH_WORDS_GETTER("getUserName.field.testNum"));
	//��λ����
	API_DTO_FIELD_DEFAULT(String,dept, ZH_WORDS_GETTER("getUserName.field.dept"));

	//�Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("getUserName.field.dept"));
	//����
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("getUserName.field.dept"));
	//������� physicalType
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("getUserName.field.dept"));
	//�Ƿ��������(0-��1-��)
	API_DTO_FIELD_DEFAULT(UInt32, sporadicPhysical, ZH_WORDS_GETTER("getUserName.field.dept"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_