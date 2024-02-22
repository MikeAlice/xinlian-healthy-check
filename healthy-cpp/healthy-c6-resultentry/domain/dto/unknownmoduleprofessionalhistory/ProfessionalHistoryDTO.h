#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/26 23:47:08

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
#ifndef _PROFESSIONALHISTORYCONTRONLLER_DTO_
#define _PROFESSIONALHISTORYCONTRONLLER_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * 定义一个修改用户信息的数据传输模型
 */
class ProfessionalHistoryDTO : public oatpp::DTO
{
	DTO_INIT(ProfessionalHistoryDTO, DTO);
	// 唯一编号
	API_DTO_FIELD_DEFAULT(String, person_id, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.person_id"));
	// 起始时间
	API_DTO_FIELD_DEFAULT(String, start_date, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.start_date"));
	// 结束时间
	API_DTO_FIELD_DEFAULT(String, end_date, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.end_date"));
	// 工作单位
	API_DTO_FIELD_DEFAULT(String, work_unit, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.work_unit"));
	// 车间（部门）
	API_DTO_FIELD_DEFAULT(String, department, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.department"));
	// 工种
	API_DTO_FIELD_DEFAULT(String, work_type_text, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.work_type_text"));
	// 危害因素
	API_DTO_FIELD_DEFAULT(String, hazard_factors_text, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.hazard_factors_text"));
	// 防护措施
	API_DTO_FIELD_DEFAULT(String, protective_measures, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.protective_measures"));
	// 接触时间
	API_DTO_FIELD_DEFAULT(String, contact_time, ZH_WORDS_GETTER("unknownmoduleprofessionalhistory.dto.contact_time"));
};

class ProfessionalHistoryPageDTO : public PageDTO<ProfessionalHistoryDTO::Wrapper>
{
	DTO_INIT(ProfessionalHistoryPageDTO, PageDTO<ProfessionalHistoryDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_