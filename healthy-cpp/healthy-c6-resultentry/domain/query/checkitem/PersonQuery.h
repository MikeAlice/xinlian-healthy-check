#pragma once
#ifndef _PERSON_H_
#define _PERSON_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
*����һ����ѯ�����Ա����������Ŀ������ݵĴ���ģ��
*/

class PersonQuery : public PageQuery
{
	DTO_INIT(PersonQuery, PageQuery);
	//��Ա���
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("checkitem.person.id"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PERSON_H_