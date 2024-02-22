#pragma once
#ifndef _CHECKLISTQUERY_H_
#define _CHECKLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * 体检人员名称列表分页查询对象
 */

class CheckListQuery : public PageQuery
{
	DTO_INIT(CheckListQuery, PageQuery);
	//项目名称（不确定写对没，先用了数据库t_lis里的“类型”，item。）
	API_DTO_FIELD_DEFAULT(String, item, ZH_WORDS_GETTER("check.field.item"));
	//原价
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("check.field.id_card"));
	//折扣
	API_DTO_FIELD_DEFAULT(UInt32, discount, ZH_WORDS_GETTER("check.field.discount"));
	//折扣价
	API_DTO_FIELD_DEFAULT(Float64, discount_price, ZH_WORDS_GETTER("check.field.discount_price"));
	//项目类型
	API_DTO_FIELD_DEFAULT(String, physical_type, ZH_WORDS_GETTER("check.field.physical_type"));

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CHECKLISTQUERY_H_