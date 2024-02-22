#pragma once

#ifndef _ORDERPERSONLISTDTO_H_
#define _ORDERPERSONLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* ��λ�б������ݶ���ʵ��
*/
class OrderPersonListDTO : public oatpp::DTO
{
	DTO_INIT(OrderPersonListDTO, DTO);
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
};

/*
* ��λ�б��ҳ����ʵ��
*/
class OrderPersonListPageDTO : public PageDTO<OrderPersonListDTO::Wrapper>
{
	DTO_INIT(OrderPersonListPageDTO, PageDTO<OrderPersonListDTO::Wrapper>);
};

#include OATPP_CODEGEN_BEGIN(DTO)

#endif // !_ORDERPERSONLISTDTO_H_
