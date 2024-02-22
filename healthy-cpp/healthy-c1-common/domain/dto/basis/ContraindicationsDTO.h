#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _CONTRAINDICATIONS_DTO_
#define _CONTRAINDICATIONS_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取职业禁忌证术语列表 传输对象
 */
class ContraindicationsDTO : public oatpp::DTO
{
	DTO_INIT(ContraindicationsDTO, DTO);
	// 术语内容
	DTO_FIELD(String, title);
	DTO_FIELD_INFO(title) 
	{
		info->description = ZH_WORDS_GETTER("basis.field.title");
	}
};

/**
 * 获取职业禁忌证术语列表 分页传输对象
 */
class ContraindicationsPageDTO : public PageDTO<ContraindicationsDTO::Wrapper>
{
	DTO_INIT(ContraindicationsPageDTO, PageDTO<ContraindicationsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CONTRAINDICATIONS_DTO_