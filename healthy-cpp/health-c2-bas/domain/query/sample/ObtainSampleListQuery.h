#pragma once
#ifndef _ObtainSampleList_QUERY_
#define _ObtainSampleList_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 样本列表分页查询实体
 */
class ObtainSampleListQuery : public PageQuery
{
	DTO_INIT(ObtainSampleListQuery, PageQuery);

	//查询类型
	API_DTO_FIELD_DEFAULT(UInt32, type, ZH_WORDS_GETTER("sample.obsl.type"));

	//名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("sample.obsl.name"));
	//样本代码
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("sample.obsl.code"));
	//关联码
	API_DTO_FIELD_DEFAULT(String, liscode, ZH_WORDS_GETTER("sample.obsl.liscode"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_