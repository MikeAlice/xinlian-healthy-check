#pragma once
#ifndef _DETAILQUERY_H_
#define _DETAILQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 单位分页查询实体
 */
class DetailQuery : public PageQuery
{
	DTO_INIT(DetailQuery, PageQuery);
	// 用户姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("detail.field.name"));
	// 用户年龄
	API_DTO_FIELD_DEFAULT(Int32, age, ZH_WORDS_GETTER("detail.field.age"));
	// 用户性别
	API_DTO_FIELD_DEFAULT(String, gender, ZH_WORDS_GETTER("detail.field.gender"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DETAILQUERY_H_