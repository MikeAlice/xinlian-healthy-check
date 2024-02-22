/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "stdafx.h"
#include "GroupApproveService.h"
#include "../../dao/groupapprove/GroupApproveDAO.h"

uint64_t GroupApproveService::saveData(const GroupApproveDTO::Wrapper& dto)
{
	// 组装DO数据
	GroupApproveDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Audit_level, audit_level, Is_info_table, is_info_table, Is_assessment_report, is_assessment_report, Is_business_license, is_business_license, Is_person_info, is_person_info, Is_entrust_report, is_entrust_report, Is_keep_record, is_keep_record, Is_equipment_true, is_equipment_true, Is_standard, is_standard, Is_understand_needs, is_understand_needs, Is_subcontract, is_subcontract, Is_special_requirements, is_special_requirements, Is_inform, is_inform, Is_take_from_oneself, is_take_from_oneself, Is_can_service, is_can_service, Reason, reason, Conclusion_person_in_charge, conclusion_person_in_charge)
		// 执行数据添加
		GroupApproveDAO dao;
	return dao.insert(data);
}

bool GroupApproveService::updateData(const GroupApproveDTO::Wrapper& dto)
{
	// 组装DO数据
	GroupApproveDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Audit_level, audit_level, Is_info_table, is_info_table, Is_assessment_report, is_assessment_report, Is_business_license, is_business_license, Is_person_info, is_person_info, Is_entrust_report, is_entrust_report, Is_keep_record, is_keep_record, Is_equipment_true, is_equipment_true, Is_standard, is_standard, Is_understand_needs, is_understand_needs, Is_subcontract, is_subcontract, Is_special_requirements, is_special_requirements, Is_inform, is_inform, Is_take_from_oneself, is_take_from_oneself, Is_can_service, is_can_service, Reason, reason, Conclusion_person_in_charge, conclusion_person_in_charge)
		// 执行数据修改
		GroupApproveDAO dao;
	return dao.update(data) == 1;
}

