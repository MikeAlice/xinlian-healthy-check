#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/01/15 18:22:06

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
#ifndef _REFERENCEMODVO_H_
#define _REFERENCEMODVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/base/ReferenceModDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* “基础项目修改指定项目的指定参考值”显示VO实体
*/
class ReferenceModJsonVO : public JsonVO<ReferenceModDTO::Wrapper>
{
	DTO_INIT(ReferenceModJsonVO, JsonVO<ReferenceModDTO::Wrapper>);
	
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_REFERENCEMODVO_H_
