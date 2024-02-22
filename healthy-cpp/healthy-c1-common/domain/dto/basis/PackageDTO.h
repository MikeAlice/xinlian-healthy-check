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

#ifndef _PACKAGE_DTO_
#define _PACKAGE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 获取套餐名称列表 传输对象
 */
class PackageDTO : public oatpp::DTO
{
	DTO_INIT(PackageDTO, DTO);
	// 套餐名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name)
	{
		info->description = ZH_WORDS_GETTER("basis.field.name");
	}
	// 套餐类型
	DTO_FIELD(String, type);
	DTO_FIELD_INFO(type)
	{
		info->description = ZH_WORDS_GETTER("basis.field.type");
	}
};

/**
 * 获取套餐名称列表 分页传输对象
 */
class PackagePageDTO : public PageDTO<PackageDTO::Wrapper>
{
	DTO_INIT(PackagePageDTO, PageDTO<PackageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_PACKAGE_DTO_