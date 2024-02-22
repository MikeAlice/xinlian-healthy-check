#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: luoluo
 @Date: 2024/1/21 10:59:38

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
#ifndef _THREELEVCHECK_DTO_
#define _THREELEVCHECK_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 三级审核传输对象
 */
class ThreeLevCheckDTO : public oatpp::DTO
{
	DTO_INIT(ThreeLevCheckDTO, DTO);
	// 复查内容表 主键
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("threelevcheck.field.id"));
	// 订单id
	API_DTO_FIELD_DEFAULT(String, orderId, ZH_WORDS_GETTER("threelevcheck.field.orderId"));
	// 评审级别
	API_DTO_FIELD_DEFAULT(String, auditLevel, ZH_WORDS_GETTER("threelevcheck.field.auditLevel"));
	// 审核结论日期
	API_DTO_FIELD_DEFAULT(String, conclusionDate, ZH_WORDS_GETTER("threelevcheck.field.conclusionDate"));
	//领导或技术负责人
	API_DTO_FIELD_DEFAULT(String, approvalPersonInCharge, ZH_WORDS_GETTER("threelevcheck.field.approvalPersonInCharge"));
	// 是否同意批准
	API_DTO_FIELD_DEFAULT(String, isAgree, ZH_WORDS_GETTER("threelevcheck.field.isAgree"));
	//不同意批准，原因
	API_DTO_FIELD_DEFAULT(String, reasonNoAgree, ZH_WORDS_GETTER("threelevcheck.field.reasonNoAgree"));
	//审核批准日期
	API_DTO_FIELD_DEFAULT(String, approvalDate, ZH_WORDS_GETTER("threelevcheck.field.approvalDate"));
	//创建人
	API_DTO_FIELD_DEFAULT(String, createId, ZH_WORDS_GETTER("threelevcheck.field.createId"));
	//创建时间
	API_DTO_FIELD_DEFAULT(String, createTime, ZH_WORDS_GETTER("threelevcheck.field.createTime"));
	//修改人
	API_DTO_FIELD_DEFAULT(String, updateId, ZH_WORDS_GETTER("threelevcheck.field.updateId"));
	//修改时间
	API_DTO_FIELD_DEFAULT(String, updateTime, ZH_WORDS_GETTER("threelevcheck.field.updateTime"));
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_THREELEVCHECK_DTO_