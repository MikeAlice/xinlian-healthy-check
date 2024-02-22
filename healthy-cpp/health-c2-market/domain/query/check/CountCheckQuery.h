#pragma once
#ifndef _COUNTCHECK_QUERY_
#define _COUNTCHECK_QUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ����ͳ����Ϣ����
 */
class CountCheckQuery : public oatpp::DTO
{
	DTO_INIT(CountCheckQuery, DTO);
	//���󼶱� 1һ����� 2������� 3������� 4������,����ֶδ�����ǲ�����4������,�൱��û��������
	//API_DTO_FIELD_DEFAULT(UInt32, audit_level_yet, ZH_WORDS_GETTER("countcheck.field.id"));
	//���󼶱� 1һ����� 2������� 3������� 4������,���������ǵ���4�����֣��൱��������
	API_DTO_FIELD_DEFAULT(UInt32, audit_level, ZH_WORDS_GETTER("countcheck.field.audit_level"));
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COUNTCHECK_QUERY_