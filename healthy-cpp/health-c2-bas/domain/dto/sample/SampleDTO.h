#pragma once
#ifndef _SAMPLE_DTO_H_
#define _SAMPLE_DTO_H_


#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

//��λ�б������ݶ���ʵ��
class SampleDTO : public oatpp::DTO
{
public:
	DTO_INIT(SampleDTO, DTO);
	// ����
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("sample.field.id"));
	//����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("sample.field.name"));
	//���
	API_DTO_FIELD_DEFAULT(String, spec, ZH_WORDS_GETTER("sample.field.spec"));
	//�걾����
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("sample.field.code"));
	//�Ƿ��ӡ
	API_DTO_FIELD_DEFAULT(Int32, is_print, ZH_WORDS_GETTER("sample.field.is_print"));
	//����
	API_DTO_FIELD_DEFAULT(String, capacity, ZH_WORDS_GETTER("sample.field.capacity"));
	//�Ƿ���Ҫ��Ѫ
	API_DTO_FIELD_DEFAULT(Int32, need_take_blood, ZH_WORDS_GETTER("sample.field.need_take_blood"));
	//����
	API_DTO_FIELD_DEFAULT(Float32, order_num, ZH_WORDS_GETTER("sample.field.order_num"));
	//������
	API_DTO_FIELD_DEFAULT(String, liscode, ZH_WORDS_GETTER("sample.field.liscode"));
};


#include OATPP_CODEGEN_END(DTO)

#endif