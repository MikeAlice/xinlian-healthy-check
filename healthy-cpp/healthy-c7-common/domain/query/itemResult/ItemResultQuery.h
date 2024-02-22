#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2024/01/17

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
#ifndef _ITEMRESULTQUERY_H_
#define _ITEMRESULTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"
#include "../../dto/getUserName/UnitListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取体检项目结论明细分页查询实体
 * 负责人：咫尺之书
 */
class ItemResultQuery : public PageQuery
{
	DTO_INIT(ItemResultQuery, PageQuery);
	// 体检项目ID
	API_DTO_FIELD_DEFAULT(String, itemId, ZH_WORDS_GETTER("itemResult.field.itemId"));
	// 人员ID
	API_DTO_FIELD_DEFAULT(String, personId, ZH_WORDS_GETTER("itemResult.field.personId"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_ITEMRESULTQUERY_H_