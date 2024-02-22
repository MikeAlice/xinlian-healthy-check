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
#ifndef _RESULTDTO_H_
#define _RESULTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  获取添加项目结论列表（分页）
 *  负责人：smartPiggy
 */
class ResultDTO : public oatpp::DTO
{
	DTO_INIT(ResultDTO, DTO);
	//唯一编号
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("result.field.id"));
	//科室
	API_DTO_FIELD_DEFAULT(String, officeName, ZH_WORDS_GETTER("result.field.officeName"));
	//组合项目
	API_DTO_FIELD_DEFAULT(String, groupItemName, ZH_WORDS_GETTER("result.field.groupItemName"));
	//体检小结
	API_DTO_FIELD_DEFAULT(String, diagnoseSum, ZH_WORDS_GETTER("result.field.diagnoseSum"));
};

class ResultPageDTO : public PageDTO<ResultDTO::Wrapper>
{
	DTO_INIT(ResultPageDTO, PageDTO<ResultDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_RESULTDTO_H_
