#pragma once
#ifndef _ADDUNIT_H_
#define _ADDUNIT_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include OATPP_CODEGEN_BEGIN(DTO)
//单位分页查询实体
class AddUnit :public PageQuery
{
	DTO_INIT(AddUnit, PageQuery);
	//查询类型
	API_DTO_FIELD_DEFAULT(UInt32, type, ZH_WORDS_GETTER("use.field.type"));
	//身份证号
	API_DTO_FIELD_DEFAULT(UInt32, id, ZH_WORDS_GETTER("use.field.id"));
	//体检姓名
	API_DTO_FIELD_DEFAULT(String, u_name, ZH_WORDS_GETTER("use.field.u_name"));
	//性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("use.field.sex"));
	//年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("use.field.age"));
	//联系电话
	API_DTO_FIELD_DEFAULT(UInt32, linkPhone, ZH_WORDS_GETTER("use.field.linkPhone"));
	//单位名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("use.field.name"));
	//婚姻状态
	API_DTO_FIELD_DEFAULT(String, marriage, ZH_WORDS_GETTER("use.field.marriage"));
	//分组名称
	API_DTO_FIELD_DEFAULT(String, g_name, ZH_WORDS_GETTER("use.field.g_name"));
};

#include OATPP_CODEGEN_END(DTO)

#endif
