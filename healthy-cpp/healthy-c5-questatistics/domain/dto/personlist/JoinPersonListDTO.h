#pragma once

#ifndef _JOINPERSONLISTDTO_H_
#define _JOINPERSONLISTDTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*��λ�б������ʵ��
*/

class JoinPersonListDTO : public oatpp::DTO
{
	DTO_INIT(JoinPersonListDTO, DTO);
	//Ψһ���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("list.field.id"));
	//�����
	API_DTO_FIELD_DEFAULT(String, testNum, ZH_WORDS_GETTER("list.field.testNum"));
	//����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("list.field.name"));
	//�Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("list.field.sex"));
	//����
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("list.field.age"));
	//���֤��
	API_DTO_FIELD_DEFAULT(UInt32, idCard, ZH_WORDS_GETTER("list.field.idCard"));
	//���״̬
	API_DTO_FIELD_DEFAULT(UInt32, checkStatus, ZH_WORDS_GETTER("list.field.checkStatus"));
	// �ڸ�״̬
	API_DTO_FIELD_DEFAULT(String, workStateText, ZH_WORDS_GETTER("list.field.workStateText"));
	//Σ������
	API_DTO_FIELD_DEFAULT(String, hazardFactor, ZH_WORDS_GETTER("list.field.hazardFactor"));
	//�������
	API_DTO_FIELD_DEFAULT(UInt32, checkDate, ZH_WORDS_GETTER("list.field.checkDate"));
	//������
	API_DTO_FIELD_DEFAULT(String, comments, ZH_WORDS_GETTER("list.field.comments"));
	//δ�����Ŀ
	API_DTO_FIELD_DEFAULT(String, unfinishedTerm, ZH_WORDS_GETTER("list.field.unfinishedTerm"));
};

/**
*��λ�б��ҳ����ʵ��
*/

class PersonListPageDTO :public PageDTO < JoinPersonListDTO::Wrapper > {
	DTO_INIT(PersonListPageDTO, PageDTO < JoinPersonListDTO::Wrapper >);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_JoinPersonListDTO_H_