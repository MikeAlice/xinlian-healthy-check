#pragma once

#ifndef _CRITICALMODIFYDTO_H_
#define _CRITICALMODIFYDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��λ�б����ݶ���ʵ��
 */
class CriticalListDTO : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(CriticalListDTO, DTO);
	//Id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("critical.field.id"));
	//�ȼ�
	API_DTO_FIELD_DEFAULT(String, level, ZH_WORDS_GETTER("critical.field.level"));
	//����
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("critical.field.type"));
	//����ֵ
	API_DTO_FIELD_DEFAULT(String, intervalValue, ZH_WORDS_GETTER("critical.field.intervalValue"));
	//�ʺ��Ա�
	API_DTO_FIELD_DEFAULT(String, allowSex, ZH_WORDS_GETTER("critical.field.allowSex"));
	//�������ֵ
	API_DTO_FIELD_DEFAULT(UInt32, minAge, ZH_WORDS_GETTER("critical.field.minAge"));
	//�������ֵ
	API_DTO_FIELD_DEFAULT(UInt32, maxAge, ZH_WORDS_GETTER("critical.field.maxAge"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_