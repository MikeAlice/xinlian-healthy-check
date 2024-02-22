#pragma once
#ifndef _POSITIVEQUERY_H_
#define _POSITIVEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���Խ����ҳ��ѯʵ��
 */
class PositiveQuery : public PageQuery {
	DTO_INIT(PositiveQuery, PageQuery);
	// ����
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("positive.filed.personname"));
	// ������
	API_DTO_FIELD_DEFAULT(String, officeName, ZH_WORDS_GETTER("positive.filed,officename"));
	// �������
	API_DTO_FIELD_DEFAULT(String, checkDate, ZH_WORDS_GETTER("positive.filed.checkdate"));
	// ���״̬ �Ƿ����� 0Ϊ���� 1Ϊ������
	API_DTO_FIELD_DEFAULT(UInt32, isNormal, ZH_WORDS_GETTER("positive.filed.isNormal"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_POSITIVEQUERY_H_