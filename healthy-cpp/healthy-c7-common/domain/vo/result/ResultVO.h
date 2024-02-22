#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: smartPiggy
 @Date: 2024-01-18

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
#ifndef _RESULTVO_H_
#define _RESULTVO_H_

#include "../../GlobalInclude.h"
#include"../../dto/result/ResultDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 项目结论列表JsonVO
*/
class ResultJsonVO : public JsonVO<ResultDTO::Wrapper>
{
	DTO_INIT(ResultJsonVO, JsonVO<ResultDTO::Wrapper>);
};
class ResultPageJsonVO : public JsonVO<ResultPageDTO::Wrapper>
{
	DTO_INIT(ResultPageJsonVO, JsonVO<ResultPageDTO::Wrapper>);
};

///*
//* 项目结论详情JsonVO
//*/
//class ItemResultJsonVO : public JsonVO<ItemResultDTO::Wrapper>
//{
//	DTO_INIT(ItemResultJsonVO, JsonVO<ItemResultDTO::Wrapper>);
//};
//class ItemResultPageJsonVO : public JsonVO<ItemResultPageDTO::Wrapper>
//{
//	DTO_INIT(ItemResultPageJsonVO, JsonVO<ItemResultPageDTO::Wrapper>)
//};


#include OATPP_CODEGEN_END(DTO)

#endif // !_RESULTVO_H_