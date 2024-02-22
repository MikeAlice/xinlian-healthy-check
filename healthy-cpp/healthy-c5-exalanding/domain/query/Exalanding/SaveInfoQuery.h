#pragma once
#ifndef _SAVE_INFO_QUERY_H_
#define _SAVE_INFO_QUERY_H_
#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个查询用户信息的数据传输模型
 */
class SaveInfoQuery : public PageQuery
{
	// 定义初始化
	DTO_INIT(SaveInfoQuery, PageQuery);
	// id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("exalanding.saveinfo.field.id"));
	// 身份证号
	API_DTO_FIELD_DEFAULT(String, id_card, ZH_WORDS_GETTER("exalanding.saveinfo.field.id_card"));
	//姓名
	API_DTO_FIELD_DEFAULT(String, person_name, ZH_WORDS_GETTER("exalanding.saveinfo.field.person_name"));
	//性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("exalanding.saveinfo.field.sex"));
	//年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("exalanding.saveinfo.field.age"));
	//联系电话
	API_DTO_FIELD_DEFAULT(String, mobile, ZH_WORDS_GETTER("exalanding.saveinfo.field.mobile"));
	//婚姻状态
	API_DTO_FIELD_DEFAULT(String, is_marry, ZH_WORDS_GETTER("exalanding.saveinfo.field.is_marry"));
	//是否通过检查(1-登记，2-在检,3-总检,4-已完成)
	API_DTO_FIELD_DEFAULT(UInt32, is_pass, ZH_WORDS_GETTER("exalanding.saveinfo.field.is_pass"));
	//体检类型
	API_DTO_FIELD_DEFAULT(String, physical_type, ZH_WORDS_GETTER("exalanding.saveinfo.field.physical_type"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAVE_INFO_QUERY_H_