#pragma once

#ifndef _SAMPLE_QUERY_
#define _SAMPLE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* 单位分页查询实体
*/

class UnitQuery : public PageQuery
{
	DTO_INIT(UnitQuery, PageQuery);
	//查询类型
	//API_DTO_FIELD_DEFAULT(UInt32,type, ZH_WORDS_GETTER("evalue.field.type"));
	//体检类型
	API_DTO_FIELD_DEFAULT(UInt32,ispass, ZH_WORDS_GETTER("getUserName.field.ispass"));
	// 复查状态  复查人员在复检人员信息表中查询
	API_DTO_FIELD_DEFAULT(UInt32, isRecheck, ZH_WORDS_GETTER("getUserName.field.isRecheck"));
	//开始时间
	API_DTO_FIELD_DEFAULT(String, startDate, ZH_WORDS_GETTER("getUserName.field.startDate"));
	//结束时间
	API_DTO_FIELD_DEFAULT(String, endDate, ZH_WORDS_GETTER("getUserName.field.endDate"));
	//姓名
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("getUserName.field.personName"));
	//体检编号
	API_DTO_FIELD_DEFAULT(String, testNum, ZH_WORDS_GETTER("getUserName.field.testNum"));
	//单位名称
	API_DTO_FIELD_DEFAULT(String,dept, ZH_WORDS_GETTER("getUserName.field.dept"));

	//性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("getUserName.field.dept"));
	//年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("getUserName.field.dept"));
	//体检类型 physicalType
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("getUserName.field.dept"));
	//是否零星体检(0-否，1-是)
	API_DTO_FIELD_DEFAULT(UInt32, sporadicPhysical, ZH_WORDS_GETTER("getUserName.field.dept"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_