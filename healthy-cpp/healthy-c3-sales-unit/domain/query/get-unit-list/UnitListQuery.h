#pragma once

#ifndef _UNITLISTQUERY_H_
#define _UNITLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 单位分页查询实体
 */
class UnitListQuery : public PageQuery
{
	DTO_INIT(UnitListQuery, PageQuery);
	//单位名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("unit.field.name"));
	//体检类型
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("unit.field.physical_type"));
	//统一社会信用代码
	API_DTO_FIELD_DEFAULT(String, uscc, ZH_WORDS_GETTER("unit.field.uscc"));
	//体检联系人
	API_DTO_FIELD_DEFAULT(String, linkMan2, ZH_WORDS_GETTER("unit.field.link_man2"));
	//体检联系人电话
	API_DTO_FIELD_DEFAULT(String, linkPhone2, ZH_WORDS_GETTER("unit.field.link_phone2"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITLISTQUERY_H_