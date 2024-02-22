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
#ifndef _PEOPLELISTVO_H_
#define _PEOPLELISTVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/Exalanding/PeopleListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class PeopleListJsonVO :public JsonVO<PeopleListDTO::Wrapper>
{
	DTO_INIT(PeopleListJsonVO, JsonVO<PeopleListDTO::Wrapper>);
};


/**
 * 定义一个体检人员名称列表分页显示JsonVO对象，用于响应给客户端
 */
class PeopleListPageJsonVO : public JsonVO<PeopleListPageDTO::Wrapper> {
	DTO_INIT(PeopleListPageJsonVO, JsonVO<PeopleListPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_