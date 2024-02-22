#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2024/01/14
 @FileName: RefValuePageJsonVO
 @version: 1.0

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
#ifndef _REF_VALUE_PAGE_JSON_VO_
#define _REF_VALUE_PAGE_JSON_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/referencevalue/RefValuePageDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class RefValuePageJsonVO : public JsonVO<RefValuePageDTO::Wrapper>
{
	DTO_INIT(RefValuePageJsonVO, JsonVO<RefValuePageDTO::Wrapper>);
public:

};

#include OATPP_CODEGEN_END(DTO)
#endif