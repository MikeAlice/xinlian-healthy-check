#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: firmiana
 @Date: 2024/01/23
 @FileName: SelectBaseProjectListVO.h
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
#ifndef _SELECT_BASEPROJECTLIST_VO_H_
#define _SELECT_BASEPROJECTLIST_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/baseproject/SelectBaseProjectListDTO.h"
#include "../../query/baseproject/SelectBaseProjectListQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class SelectBaseProjectListJsonVO : public JsonVO<SelectBaseProjectListDTO::Wrapper>
{
	DTO_INIT(SelectBaseProjectListJsonVO, JsonVO<SelectBaseProjectListDTO::Wrapper>);
};

class SelectBaseProjectListPageJsonVO : public JsonVO<SelectBaseProjectListPageDTO::Wrapper>
{
	DTO_INIT(SelectBaseProjectListPageJsonVO, JsonVO<SelectBaseProjectListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SELECT_BASEPROJECTLIST_VO_H_
