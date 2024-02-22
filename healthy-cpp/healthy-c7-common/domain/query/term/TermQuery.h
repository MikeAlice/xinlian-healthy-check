#pragma once
#ifndef  _TERMQUERY_H_
#define _TERMQUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 单位分页查询实体
 */
class TermQuery :public PageQuery
{
	DTO_INIT(TermQuery, PageQuery);
	//ID
	API_DTO_FIELD_DEFAULT(String, officeId, ZH_WORDS_GETTER("term.field.officeId"));
	//危害因素
	API_DTO_FIELD_DEFAULT(String, hazardFactorsText, ZH_WORDS_GETTER("term.field.hazardFactorsText"));
	// 类型
	API_DTO_FIELD_DEFAULT(String, inspectType, ZH_WORDS_GETTER("term.field.inspectType"));
	// 内容
	API_DTO_FIELD_DEFAULT(String, content, ZH_WORDS_GETTER("term.field.content"));
	//在岗状态
	API_DTO_FIELD_DEFAULT(String, workStateText, ZH_WORDS_GETTER("term.field.workStateText"));
};

#include OATPP_CODEGEN_END(DTO)

#endif