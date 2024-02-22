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
#ifndef _ITEMRESULTDTO_H_
#define _ITEMRESULTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取体检项目结果明细传输数据对象实体
 * 负责人：咫尺之书
 */
class ItemResultDTO : public oatpp::DTO
{
	DTO_INIT(ItemResultDTO, DTO);
	// 体检项目名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("itemResult.field.name"));
	// 结果
	API_DTO_FIELD_DEFAULT(String, defaultValue, ZH_WORDS_GETTER("itemResult.field.defaultValue"));
	// 单位
	API_DTO_FIELD_DEFAULT(String, unitName, ZH_WORDS_GETTER("itemResult.field.unitName"));
	// 参考范围
	API_DTO_FIELD_DEFAULT(String, scope, ZH_WORDS_GETTER("itemResult.field.scope"));
public:
	ItemResultDTO(String n, String d, String u, String s)
	{
		name = n;
		defaultValue = d;
		unitName = u;
		scope = s;
	}
	ItemResultDTO()
	{
		name = "";
		defaultValue = "";
		unitName = "";
		scope = "";
	}
};
/**
 * 获取体检项目结果明细分页数据实体
 * 负责人：咫尺之书
 */
class ItemResultPageDTO : public PageDTO<ItemResultDTO::Wrapper>
{
	DTO_INIT(ItemResultPageDTO, PageDTO<ItemResultDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_ITEMRESULTDTO_H_