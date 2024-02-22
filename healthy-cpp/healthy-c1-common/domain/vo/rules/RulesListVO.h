#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: c1-pepper
 @Date: 2024/1/15

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
#ifndef _RULESLISTVO_H_
#define _RULESLISTVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/rules/RulesListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个示例菜单显示JsonVO对象，用于响应给前端
 */
class RulesListJsonVO : public JsonVO<RulesListDTO::Wrapper>
{
	DTO_INIT(RulesListJsonVO, JsonVO<RulesListDTO::Wrapper>);
public:
	// 在构造函数中实例化data列表
	RulesListJsonVO() {
		this->data = {};
	}
};
/**
 * 定义一个用户信息分页显示JsonVO对象，用于响应给客户端
 */
class RulesListPageJsonVO : public JsonVO<RulesListPageDTO::Wrapper>
{
	DTO_INIT(RulesListPageJsonVO, JsonVO<RulesListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RULESLISTVO_H_