#pragma once
#ifndef _JOINPERSONLISTQUERY_H_
#define _JOINPERSONLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*��λ��ҳ��ѯʵ��
*/

class JoinPersonListQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(JoinPersonListQuery, DTO);
	// ��ѯ����
	API_DTO_FIELD_DEFAULT(UInt32, type, ZH_WORDS_GETTER("check.field.type"));
	//�����
	API_DTO_FIELD_DEFAULT(String, testNum, ZH_WORDS_GETTER("check.field.testNum"));
	//�������
	API_DTO_FIELD_DEFAULT(String, checkClass, ZH_WORDS_GETTER("check.field.checkClass"));
	//����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("check.field.name"));
	//���֤��
	API_DTO_FIELD_DEFAULT(UInt32, idCard, ZH_WORDS_GETTER("check.field.idCard"));
	//Σ������
	API_DTO_FIELD_DEFAULT(String, hazardFactor, ZH_WORDS_GETTER("check.field.hazardFactor"));
	//״̬
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("check.field.status"));
	//�Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("check.field.sex"));
	//�������
	API_DTO_FIELD_DEFAULT(UInt32, checkDate, ZH_WORDS_GETTER("check.field.checkDate"));
	//������
	API_DTO_FIELD_DEFAULT(String, comments, ZH_WORDS_GETTER("check.field.comments"));
}; 
#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_