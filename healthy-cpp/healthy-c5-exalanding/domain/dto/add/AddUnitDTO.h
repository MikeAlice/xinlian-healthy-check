#pragma once
#ifndef _ADDUNITDTO_H_
#define _ADDUNITDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//单位列表传输数据对象实体
class AddUnitDTO :public oatpp::DTO
{
	DTO_INIT(AddUnitDTO, DTO);
	//查询类型
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("use.field.type"));
	//身份证号
	API_DTO_FIELD_DEFAULT(UInt32, idCard, ZH_WORDS_GETTER("use.field.id"));
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
	//是否保存
	API_DTO_FIELD_DEFAULT(UInt32, save_if, ZH_WORDS_GETTER("use.field.save"));
	//状态
	API_DTO_FIELD_DEFAULT(UInt32, is_pass, ZH_WORDS_GETTER("use.field.pass"));
};
//分页用的数据实体
class AddPageDTO : public PageDTO<AddUnitDTO::Wrapper> {

	DTO_INIT(AddUnitDTO, PageDTO<AddUnitDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif

