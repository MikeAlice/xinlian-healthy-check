#pragma once

#ifndef _ORDEROUTPUT_QUERY_
#define _ORDEROUTPUT_QUERY_
#include"../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)
class ExportPersonQuery :public oatpp::DTO
{
	DTO_INIT(ExportPersonQuery, DTO);
	//订单id
	API_DTO_FIELD_DEFAULT(String, orderId, ZH_WORDS_GETTER("person.field.order_id"));
	//是否通过检查(0-未登记, 1-登记, 2-在检, 3-总检, 4-已完成)
	API_DTO_FIELD_DEFAULT(Int32, isPass, ZH_WORDS_GETTER("person.field.is_pass"));
};
#include OATPP_CODEGEN_END(DTO)
#endif