#pragma once
#ifndef _CRITICALQUERY_H_
#define _CRITICALQUERY_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ�û���Ϣ�����ݲ�ѯģ��
 */
class CriticalQuery : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(CriticalQuery, DTO);
	//Id
	API_DTO_FIELD_DEFAULT(UInt64, id, ZH_WORDS_GETTER("critical.field.id"));
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