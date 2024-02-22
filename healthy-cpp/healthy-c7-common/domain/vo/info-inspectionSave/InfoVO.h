#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: DY
 @Date: 2022/01/16 11:34:14

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
#ifndef _UNITVO_H_
#define _UNITVO_H_

#include "../../GlobalInclude.h"
#include "domain/dto/info-inspectionSave/InfoListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 单位列表显示JsonVO实体
 */
class InfoJsonVO : public JsonVO<InfoListDTO::Wrapper> {
	DTO_INIT(InfoJsonVO, JsonVO<InfoListDTO::Wrapper>);
};

/**
 * 单位列表显示分页JsonVO实体
 */
class InfoListPageJsonVO : public JsonVO<InfoListPageDTO::Wrapper> {
	DTO_INIT(InfoListPageJsonVO, JsonVO<InfoListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_VO_