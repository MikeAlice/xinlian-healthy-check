#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _UnitListDTO_H_
#define _UnitListDTO_H_

#include "../../GlobalInclude.h" 

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 单位列表传输数据对象实体
*/
class UnitListDTO : public oatpp::DTO
{
	DTO_INIT(UnitListDTO, DTO);
	//姓名
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("getUserName.field.personName"));
	//性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("getUserName.field.sex"));
	// 年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("getUserName.field.age"));
	//体检类型 physicalType
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("getUserName.field.physicalType"));
	//是否零星体检(0-否，1-是)
	API_DTO_FIELD_DEFAULT(UInt32, sporadicPhysical, ZH_WORDS_GETTER("getUserName.field.sporadicPhysical"));
};

/*
* 单位列表分页传输数据对象实体
*/
class UnitListPageDTO : public PageDTO<UnitListDTO::Wrapper> {
	DTO_INIT(UnitListPageDTO, PageDTO<UnitListDTO::Wrapper>);
	/*
	//姓名
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("getUserName.field.personName"));
	//性别
	API_DTO_FIELD_DEFAULT(String, sex, ZH_WORDS_GETTER("getUserName.field.sex"));
	// 年龄
	API_DTO_FIELD_DEFAULT(UInt32, age, ZH_WORDS_GETTER("getUserName.field.age"));
	//体检类型 physicalType
	API_DTO_FIELD_DEFAULT(String, physicalType, ZH_WORDS_GETTER("getUserName.field.physicalType"));
	//否零星体检(0-否，1-是)
	API_DTO_FIELD_DEFAULT(UInt32, sporadicPhysical, ZH_WORDS_GETTER("getUserName.field.sporadicPhysical"));
	*/
};
#include OATPP_CODEGEN_END(DTO)
#endif // 