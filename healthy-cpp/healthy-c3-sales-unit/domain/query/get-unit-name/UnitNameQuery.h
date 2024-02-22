#pragma once

#ifndef _UNITNAMEQUERY_H_
#define _UNITNAMEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ��λ�����б���������������б��    �����ˣ�Tutu��ͿͿ
 */
class UnitNameQuery : public PageQuery
{
	DTO_INIT(UnitNameQuery, DTO);
	// ��ѯ����
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("unit.field.physical_type"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITNAMEQUERY_H_
