#pragma once
#ifndef _NAMELIST_H_
#define _NAMELIST_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询用户信息的数据传输模型
 */
class NameListQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(NameListQuery, PageQuery);
	// 查询类型
	API_DTO_FIELD_DEFAULT(UInt32, type, ZH_WORDS_GETTER("contract.field.type"));
	// 是否过审
	API_DTO_FIELD_DEFAULT(UInt32, auditState, ZH_WORDS_GETTER("contract.field.auditState"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_