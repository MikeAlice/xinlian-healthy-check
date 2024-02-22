#pragma once
#ifndef _ADDUNITDTO_H_
#define _ADDUNITDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//��λ�б������ݶ���ʵ��
class AddUnitDTO :public oatpp::DTO
{
	DTO_INIT(AddUnitDTO, DTO);
	//��ѯ����
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("use.field.type"));
	//���֤��
	API_DTO_FIELD_DEFAULT(UInt32, idCard, ZH_WORDS_GETTER("use.field.id"));
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
	//�Ƿ񱣴�
	API_DTO_FIELD_DEFAULT(UInt32, save_if, ZH_WORDS_GETTER("use.field.save"));
	//״̬
	API_DTO_FIELD_DEFAULT(UInt32, is_pass, ZH_WORDS_GETTER("use.field.pass"));
};
//��ҳ�õ�����ʵ��
class AddPageDTO : public PageDTO<AddUnitDTO::Wrapper> {

	DTO_INIT(AddUnitDTO, PageDTO<AddUnitDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif

