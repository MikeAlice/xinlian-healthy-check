#pragma once
#ifndef _COUNTCHECK_QUERY_
#define _COUNTCHECK_QUERY_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取审批统计信息对象
 */
class CountCheckQuery : public oatpp::DTO
{
	DTO_INIT(CountCheckQuery, DTO);
	//评审级别 1一级审核 2二级审核 3三级审核 4完成审核,这个字段传入的是不等于4的数字,相当于没有完成审核
	//API_DTO_FIELD_DEFAULT(UInt32, audit_level_yet, ZH_WORDS_GETTER("countcheck.field.id"));
	//评审级别 1一级审核 2二级审核 3三级审核 4完成审核,这个传入的是等于4的数字，相当于完成审核
	API_DTO_FIELD_DEFAULT(UInt32, audit_level, ZH_WORDS_GETTER("countcheck.field.audit_level"));
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COUNTCHECK_QUERY_