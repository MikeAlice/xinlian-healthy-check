#pragma once
#ifndef _COUNTCHECK_DTO_
#define _COUNTCHECK_DTO_


#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

//��ȡ������Ϣ�������ݶ���ʵ��
class CountCheckDTO : public oatpp::DTO
{
public:
	DTO_INIT(CountCheckDTO, DTO);
	// ���������
	API_DTO_FIELD_DEFAULT(UInt64, already, ZH_WORDS_GETTER("countcheck.field.already1"));
	//δ�������
	API_DTO_FIELD_DEFAULT(UInt64, yet, ZH_WORDS_GETTER("countcheck.field.yet"));
	
};


#include OATPP_CODEGEN_END(DTO)

#endif
