#pragma once

#ifndef _ORDERPERSONLISTDTO_H_
#define _ORDERPERSONLISTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 单位列表传输数据对象实体
*/
class OrderPersonListDTO : public oatpp::DTO
{
	DTO_INIT(OrderPersonListDTO, DTO);
	//主键
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("person.field.id"));
	//人员姓名
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("person.field.person_name"));
	//性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("person.field.sex"));
	//证件号码
	API_DTO_FIELD_DEFAULT(String, idCard, ZH_WORDS_GETTER("person.field.id_card"));
	//年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("person.field.age"));
};

/*
* 单位列表分页数据实体
*/
class OrderPersonListPageDTO : public PageDTO<OrderPersonListDTO::Wrapper>
{
	DTO_INIT(OrderPersonListPageDTO, PageDTO<OrderPersonListDTO::Wrapper>);
};

#include OATPP_CODEGEN_BEGIN(DTO)

#endif // !_ORDERPERSONLISTDTO_H_
