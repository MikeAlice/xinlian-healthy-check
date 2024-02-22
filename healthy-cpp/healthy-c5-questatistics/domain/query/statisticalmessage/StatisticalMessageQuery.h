#pragma once
#ifndef _STATISTICALMESSAGEQUERY_H_
#define _STATISTICALMESSAGEQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*��ȡͳ����Ϣ
*/

class StatisticalMessageQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(StatisticalMessageQuery, DTO);
	// ��������-���״̬
	API_DTO_FIELD_DEFAULT(UInt32, isPass, ZH_WORDS_GETTER("statistica.rate.isPass"));
	// ���������
	//API_DTO_FIELD_DEFAULT(UInt32, evCompletionRate, ZH_WORDS_GETTER("statistica.rate.evCompletionRate"));

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_