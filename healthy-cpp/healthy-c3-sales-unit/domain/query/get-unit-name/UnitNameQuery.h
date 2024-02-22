#pragma once

#ifndef _UNITNAMEQUERY_H_
#define _UNITNAMEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取单位名称列表（用于输入表单下拉列表框）    负责人：Tutu糊涂涂
 */
class UnitNameQuery : public PageQuery
{
	DTO_INIT(UnitNameQuery, DTO);
	// 查询类型
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("unit.field.physical_type"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITNAMEQUERY_H_
