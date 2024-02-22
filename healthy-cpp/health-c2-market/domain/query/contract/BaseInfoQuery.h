#pragma once
#ifndef _BASEINFO_H_
#define _BASEINFO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询用户信息的数据传输模型
 */
class BaseInfoQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(BaseInfoQuery, PageQuery);
	// 签订时间
	API_DTO_FIELD_DEFAULT(String, signingTime, ZH_WORDS_GETTER("contract.field.signingTime"));
	// 委托单位
	API_DTO_FIELD_DEFAULT(String, groupUnitName, ZH_WORDS_GETTER("contract.field.groupUnitName"));
	//是否过审
	API_DTO_FIELD_DEFAULT(UInt32, auditState, ZH_WORDS_GETTER("contract.field.auditState"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_
