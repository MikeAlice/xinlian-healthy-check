#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: duifang
 @Date: 2024/1/17 11:36:29

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
#ifndef _PEOPLELISTQUERY_H_
#define _PEOPLELISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * 体检人员名称列表分页查询对象
 */
class PeopleListQuery : public PageQuery
{
	DTO_INIT(PeopleListQuery, PageQuery);
	//人员姓名
	API_DTO_FIELD_DEFAULT(String, personName, ZH_WORDS_GETTER("Exalanding.field.personName"));
	//体检类型
	API_DTO_FIELD_DEFAULT(String, physical, ZH_WORDS_GETTER("Exalanding.field.physical"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_