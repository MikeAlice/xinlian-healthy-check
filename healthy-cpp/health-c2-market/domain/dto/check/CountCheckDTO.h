#pragma once
#ifndef _COUNTCHECK_DTO_
#define _COUNTCHECK_DTO_


#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

//获取审批信息传输数据对象实体
class CountCheckDTO : public oatpp::DTO
{
public:
	DTO_INIT(CountCheckDTO, DTO);
	// 已审核数量
	API_DTO_FIELD_DEFAULT(UInt64, already, ZH_WORDS_GETTER("countcheck.field.already1"));
	//未审核数量
	API_DTO_FIELD_DEFAULT(UInt64, yet, ZH_WORDS_GETTER("countcheck.field.yet"));
	
};


#include OATPP_CODEGEN_END(DTO)

#endif
