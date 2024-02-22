#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _CLABANPROJDTO_H_
#define _CLABANPROJDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例传输对象
 */
class ClAbanProjDTO : public oatpp::DTO
{
	DTO_INIT(ClAbanProjDTO, DTO);
	//人员id
	DTO_FIELD(String, personId);
	DTO_FIELD_INFO(personId) {
		info->description = ZH_WORDS_GETTER("result-entry.cl-aban-proj.field.personid");
	}
	//科室id
	DTO_FIELD(String, officeId);
	DTO_FIELD_INFO(officeId) {
		info->description = ZH_WORDS_GETTER("result-entry.cl-aban-proj.field.office-id");
	}
	//分组项目id
	DTO_FIELD(String, orderGroupItemId);
	DTO_FIELD_INFO(orderGroupItemId) {
		info->description = ZH_WORDS_GETTER("result-entry.cl-aban-proj.field.order-group-item-id");
	}

};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_