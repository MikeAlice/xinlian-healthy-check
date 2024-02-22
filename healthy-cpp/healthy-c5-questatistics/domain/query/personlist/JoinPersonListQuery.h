#pragma once
#ifndef _JOINPERSONLISTQUERY_H_
#define _JOINPERSONLISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*单位分页查询实体
*/

class JoinPersonListQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(JoinPersonListQuery, DTO);
	// 查询类型
	API_DTO_FIELD_DEFAULT(UInt32, type, ZH_WORDS_GETTER("check.field.type"));
	//体检编号
	API_DTO_FIELD_DEFAULT(String, testNum, ZH_WORDS_GETTER("check.field.testNum"));
	//检查种类
	API_DTO_FIELD_DEFAULT(String, checkClass, ZH_WORDS_GETTER("check.field.checkClass"));
	//姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("check.field.name"));
	//身份证号
	API_DTO_FIELD_DEFAULT(UInt32, idCard, ZH_WORDS_GETTER("check.field.idCard"));
	//危害因素
	API_DTO_FIELD_DEFAULT(String, hazardFactor, ZH_WORDS_GETTER("check.field.hazardFactor"));
	//状态
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("check.field.status"));
	//性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("check.field.sex"));
	//体检日期
	API_DTO_FIELD_DEFAULT(UInt32, checkDate, ZH_WORDS_GETTER("check.field.checkDate"));
	//体检结论
	API_DTO_FIELD_DEFAULT(String, comments, ZH_WORDS_GETTER("check.field.comments"));
}; 
#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_