/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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
#include "GroupApproveDAO.h"
#include "GroupApproveMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->id) { \
	sql << " AND `id`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->id.getValue(0)); \
} \
if (query->audit_level) { \
	sql << " AND audit_level=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->audit_level.getValue(0)); \
} \
if (query->is_info_table) { \
	sql << " AND is_info_table=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_info_table.getValue("")); \
}\
if (query->is_assessment_report) { \
	sql << " AND `is_assessment_report`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_assessment_report.getValue("")); \
} \
if (query->is_business_license) { \
	sql << " AND is_business_license=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_business_license.getValue("")); \
} \
if (query->is_person_info) { \
	sql << " AND is_person_info=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_person_info.getValue("")); \
}\
if (query->is_entrust_report) { \
	sql << " AND `is_entrust_report`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_entrust_report.getValue("")); \
} \
if (query->is_keep_record) { \
	sql << " AND is_keep_record=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_keep_record.getValue("")); \
} \
if (query->is_equipment_true) { \
	sql << " AND `is_equipment_true`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_equipment_true.getValue("")); \
} \
if (query->is_standard) { \
	sql << " AND is_standard=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_standard.getValue("")); \
} \
if (query->is_understand_needs) { \
	sql << " AND is_understand_needs=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_understand_needs.getValue("")); \
}\
if (query->is_subcontract) { \
	sql << " AND `is_subcontract`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_subcontract.getValue("")); \
} \
if (query->is_special_requirements) { \
	sql << " AND is_special_requirements=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_special_requirements.getValue("")); \
} \
if (query->is_inform) { \
	sql << " AND is_inform=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_inform.getValue("")); \
}\
if (query->is_take_from_oneself) { \
	sql << " AND `is_take_from_oneself`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_take_from_oneself.getValue("")); \
} \
if (query->is_can_service) { \
	sql << " AND is_can_service=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->is_can_service.getValue("")); \
} \
if (query->reason) { \
	sql << " AND reason=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->reason.getValue("")); \
}\
if (query->conclusion_person_in_charge) { \
	sql << " AND conclusion_person_in_charge=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->conclusion_person_in_charge.getValue("")); \
} \



uint64_t GroupApproveDAO::insert(const GroupApproveDO& iObj)
{
	string sql = "INSERT INTO `t_review_content` (`id`, `audit_level`, `is_info_table`, `is_assessment_report`, `is_business_license`, `is_person_info`, `is_entrust_report`, `is_keep_record`, `is_equipment_true`, `is_standard`, `is_understand_needs`, `is_subcontract`, `is_special_requirements`, `is_inform`, `is_take_from_oneself`, `is_can_service`, `reason`, `conclusion_person_in_charge`) VALUES(? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? )";
	return sqlSession->executeInsert(sql, "%i%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",  iObj.getAudit_level(), iObj.getIs_info_table(), iObj.getIs_assessment_report(), iObj.getIs_business_license(), iObj.getIs_person_info(),
		iObj.getIs_entrust_report(), iObj.getIs_keep_record(), iObj.getIs_equipment_true(), iObj.getIs_standard(), iObj.getIs_understand_needs(),
		iObj.getIs_subcontract(), iObj.getIs_special_requirements(), iObj.getIs_inform(), iObj.getIs_take_from_oneself(), iObj.getIs_can_service(),
		iObj.getReason(), iObj.getConclusion_person_in_charge());
}

int GroupApproveDAO::update(const GroupApproveDO& uObj)
{
	string sql = "UPDATE `t_review_content` SET `audit_level`=?, `is_info_table`=?, `is_assessment_report`=?, `is_business_license`=?, `is_person_info`=?, `is_entrust_report`=?, `is_keep_record`=?, `is_equipment_true`=?, `is_standard`=?, `is_understand_needs`=?, `is_subcontract`=?, `is_special_requirements`=?, `is_inform`=?, `is_take_from_oneself`=?, `is_can_service`=?, `reason`=?, `conclusion_person_in_charge`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%ull%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%ull", uObj.getAudit_level(), uObj.getIs_info_table(), uObj.getIs_assessment_report(), uObj.getIs_business_license(), uObj.getIs_person_info(),
		uObj.getIs_entrust_report(), uObj.getIs_keep_record(), uObj.getIs_equipment_true(), uObj.getIs_standard(), uObj.getIs_understand_needs(),
		uObj.getIs_subcontract(), uObj.getIs_special_requirements(), uObj.getIs_inform(), uObj.getIs_take_from_oneself(), uObj.getIs_can_service(),
		uObj.getReason(), uObj.getConclusion_person_in_charge() ,uObj.getId());
}

