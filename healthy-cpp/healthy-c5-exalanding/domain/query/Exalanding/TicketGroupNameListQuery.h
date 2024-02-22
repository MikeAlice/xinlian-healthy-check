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
#ifndef _TICKETGROUPNAMELISTQUERY_H_
#define _TICKETGROUPNAMELISTQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
 * 团单分组名称列表分页查询对象
 */
class TicketGroupNameListQuery : public PageQuery
{
	DTO_INIT(TicketGroupNameListQuery, PageQuery);
	//单位名称
	API_DTO_FIELD_DEFAULT(String, Unit_name, ZH_WORDS_GETTER("Exalanding.field.Unit_name"));
	/*DTO_FIELD(String, Unit_name);
	DTO_FIELD_INFO(Unit_name) {
		info->description = ZH_WORDS_GETTER("exalanding.field.Unit_name");
	}*/
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_