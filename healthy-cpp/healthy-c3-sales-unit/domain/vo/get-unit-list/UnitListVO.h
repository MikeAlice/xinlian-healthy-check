#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/13 19:28:34

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
#ifndef _UNITLISTVO_H_
#define _UNITLISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/get-unit-list/UnitListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 单位列表显示JsonVO实体
 */
class UnitListJsonVO : public JsonVO<UnitListDTO::Wrapper>
{
	DTO_INIT(UnitListJsonVO, JsonVO<UnitListDTO::Wrapper>);
};

/**
 * 单位列表显示分页JsonVO实体
 */
class UnitListPageJsonVO : public JsonVO<UnitListPageDTO::Wrapper> {
	DTO_INIT(UnitListPageJsonVO, JsonVO<UnitListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UNITLISTVO_H_