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
#ifndef _GROUPAPPROVE_DTO_
#define _GROUPAPPROVE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 合同一级、二级审批
 */
class GroupApproveDTO : public oatpp::DTO
{
	DTO_INIT(GroupApproveDTO, DTO);
	// 订单编号
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.id");
	}
	// 评审级别
	DTO_FIELD(UInt64, audit_level);
	DTO_FIELD_INFO(audit_level) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.audit_level");
	}
	// 用人单位基本情况信息表是否存在
	DTO_FIELD(String, is_info_table);
	DTO_FIELD_INFO(is_info_table) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_info_table");
	}
	// 近期职业病危害因素检测报告或评价报告是否存在
	DTO_FIELD(String, is_assessment_report);
	DTO_FIELD_INFO(is_assessment_report) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_assessment_report");
	}
	// 营业执照（三证合一）是否存在
	DTO_FIELD(String, is_business_license);
	DTO_FIELD_INFO(is_business_license) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_business_license");
	}
	// 预体检人员名单信息是否存在
	DTO_FIELD(String, is_person_info);
	DTO_FIELD_INFO(is_person_info) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_person_info");
	}
	// 合同（委托书）是否存在
	DTO_FIELD(String, is_entrust_report);
	DTO_FIELD_INFO(is_entrust_report) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_entrust_report");
	}
	// 检查类别和项目是否与备案一致
	DTO_FIELD(String, is_keep_record);
	DTO_FIELD_INFO(is_keep_record) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_keep_record");
	}
	// 仪器设备是否满足合同（协议）所订职业健康检查需求
	DTO_FIELD(String, is_equipment_true);
	DTO_FIELD_INFO(is_equipment_true) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_equipment_true");
	}
	// 委托单位要求是否符合国家有关法律、政策和标准规范的要求
	DTO_FIELD(String, is_standard);
	DTO_FIELD_INFO(is_standard) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_standard");
	}
	// 是否与委托单位进行了真实而有效的沟通，了解委托单位的真实需求
	DTO_FIELD(String, is_understand_needs);
	DTO_FIELD_INFO(is_understand_needs) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_understand_needs");
	}
	// 是否涉及项目分包
	DTO_FIELD(String, is_subcontract);
	DTO_FIELD_INFO(is_subcontract) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_subcontract");
	}
	// 委托方对体检时间、期限有无特别要求
	DTO_FIELD(String, is_special_requirements);
	DTO_FIELD_INFO(is_special_requirements) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_special_requirements");
	}
	// 是否告知委托方体检方案及体检注意事项
	DTO_FIELD(String, is_inform);
	DTO_FIELD_INFO(is_inform) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_inform");
	}
	// 是否委托方自取
	DTO_FIELD(String, is_take_from_oneself);
	DTO_FIELD_INFO(is_take_from_oneself) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_take_from_oneself");
	}
	/**
	 合同二级审批
    **/
	// 是否可以为委托单位提供职业健康检查服务
	DTO_FIELD(String, is_can_service);
	DTO_FIELD_INFO(is_can_service) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_can_service");
	}
	//  不能为委托单位提供职业健康检查服务，原因
	DTO_FIELD(String, reason);
	DTO_FIELD_INFO(reason) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.reason");
	}
	// 质控科负责人或体检中心负责人
	DTO_FIELD(String, conclusion_person_in_charge);
	DTO_FIELD_INFO(conclusion_person_in_charge) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.conclusion_person_in_charge");
	}
};




#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUPAPPROVE_DTO_
