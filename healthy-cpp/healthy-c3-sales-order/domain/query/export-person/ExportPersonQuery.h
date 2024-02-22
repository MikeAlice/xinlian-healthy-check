#pragma once

#ifndef _ORDEROUTPUT_QUERY_
#define _ORDEROUTPUT_QUERY_
#include"../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)
class ExportPersonQuery :public oatpp::DTO
{
	DTO_INIT(ExportPersonQuery, DTO);
	//����id
	API_DTO_FIELD_DEFAULT(String, orderId, ZH_WORDS_GETTER("person.field.order_id"));
	//�Ƿ�ͨ�����(0-δ�Ǽ�, 1-�Ǽ�, 2-�ڼ�, 3-�ܼ�, 4-�����)
	API_DTO_FIELD_DEFAULT(Int32, isPass, ZH_WORDS_GETTER("person.field.is_pass"));
};
#include OATPP_CODEGEN_END(DTO)
#endif