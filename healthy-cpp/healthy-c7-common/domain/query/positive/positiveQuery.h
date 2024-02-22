#pragma once
#ifndef _POSITIVEQUERY_H_
#define _POSITIVEQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 阳性结果分页查询实体
 */
class PositiveQuery : public PageQuery {
	DTO_INIT(PositiveQuery, PageQuery);
	// 姓名
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("positive.filed.personname"));
	// 体检科室
	API_DTO_FIELD_DEFAULT(String, officeName, ZH_WORDS_GETTER("positive.filed,officename"));
	// 体检日期
	API_DTO_FIELD_DEFAULT(String, checkDate, ZH_WORDS_GETTER("positive.filed.checkdate"));
	// 结果状态 是否正常 0为正常 1为不正常
	API_DTO_FIELD_DEFAULT(UInt32, isNormal, ZH_WORDS_GETTER("positive.filed.isNormal"));
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_POSITIVEQUERY_H_