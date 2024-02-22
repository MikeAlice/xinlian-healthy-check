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
#ifndef _TICKETGROUPNAMELIST_H_
#define _TICKETGROUPNAMELIST_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 体检人员名称列表分页数据传输模型
 */
class TicketGroupNameListDTO : public oatpp::DTO
{
	DTO_INIT(TicketGroupNameListDTO, DTO);

	// 分组名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("Exalanding.field.name"));
	// 分组名称
	/*DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("exalanding.field.name");
	}*/
};

/**
 * 体检人员名称列表分页传输对象
 */
class TicketGroupNameListPageDTO : public PageDTO<TicketGroupNameListDTO::Wrapper>
{
	DTO_INIT(TicketGroupNameListPageDTO, PageDTO<TicketGroupNameListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_