#pragma once
#ifndef _ADDUNIT_H_
#define _ADDUNIT_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
//��λ��ҳ��ѯʵ��
class AddUnit :public PageQuery
{
	DTO_INIT(AddUnit, PageQuery);
	//��ѯ����
	API_DTO_FIELD_DEFAULT(UInt32, type, ZH_WORDS_GETTER("use.field.type"));
	//���֤��
	API_DTO_FIELD_DEFAULT(UInt32, id, ZH_WORDS_GETTER("use.field.id"));
	//�������
	API_DTO_FIELD_DEFAULT(String, u_name, ZH_WORDS_GETTER("use.field.u_name"));
	//�Ա�
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("use.field.sex"));
	//����
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("use.field.age"));
	//��ϵ�绰
	API_DTO_FIELD_DEFAULT(UInt32, linkPhone, ZH_WORDS_GETTER("use.field.linkPhone"));
	//��λ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("use.field.name"));
	//����״̬
	API_DTO_FIELD_DEFAULT(String, marriage, ZH_WORDS_GETTER("use.field.marriage"));
	//��������
	API_DTO_FIELD_DEFAULT(String, g_name, ZH_WORDS_GETTER("use.field.g_name"));
};

#include OATPP_CODEGEN_END(DTO)

#endif
