#pragma once

#ifndef _JOINPERSONLISTDTO_H_
#define _JOINPERSONLISTDTO_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
*单位列表传输对象实体
*/

class JoinPersonListDTO : public oatpp::DTO
{
	DTO_INIT(JoinPersonListDTO, DTO);
	//唯一编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("list.field.id"));
	//体检编号
	API_DTO_FIELD_DEFAULT(String, testNum, ZH_WORDS_GETTER("list.field.testNum"));
	//姓名
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("list.field.name"));
	//性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("list.field.sex"));
	//年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("list.field.age"));
	//身份证号
	API_DTO_FIELD_DEFAULT(UInt32, idCard, ZH_WORDS_GETTER("list.field.idCard"));
	//体检状态
	API_DTO_FIELD_DEFAULT(UInt32, checkStatus, ZH_WORDS_GETTER("list.field.checkStatus"));
	// 在岗状态
	API_DTO_FIELD_DEFAULT(String, workStateText, ZH_WORDS_GETTER("list.field.workStateText"));
	//危害因素
	API_DTO_FIELD_DEFAULT(String, hazardFactor, ZH_WORDS_GETTER("list.field.hazardFactor"));
	//体检日期
	API_DTO_FIELD_DEFAULT(UInt32, checkDate, ZH_WORDS_GETTER("list.field.checkDate"));
	//体检结论
	API_DTO_FIELD_DEFAULT(String, comments, ZH_WORDS_GETTER("list.field.comments"));
	//未完成项目
	API_DTO_FIELD_DEFAULT(String, unfinishedTerm, ZH_WORDS_GETTER("list.field.unfinishedTerm"));
};

/**
*单位列表分页数据实体
*/

class PersonListPageDTO :public PageDTO < JoinPersonListDTO::Wrapper > {
	DTO_INIT(PersonListPageDTO, PageDTO < JoinPersonListDTO::Wrapper >);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_JoinPersonListDTO_H_