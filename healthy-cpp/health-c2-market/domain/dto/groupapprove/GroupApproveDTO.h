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
 * ��ͬһ������������
 */
class GroupApproveDTO : public oatpp::DTO
{
	DTO_INIT(GroupApproveDTO, DTO);
	// �������
	DTO_FIELD(UInt64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.id");
	}
	// ���󼶱�
	DTO_FIELD(UInt64, audit_level);
	DTO_FIELD_INFO(audit_level) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.audit_level");
	}
	// ���˵�λ���������Ϣ���Ƿ����
	DTO_FIELD(String, is_info_table);
	DTO_FIELD_INFO(is_info_table) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_info_table");
	}
	// ����ְҵ��Σ�����ؼ�ⱨ������۱����Ƿ����
	DTO_FIELD(String, is_assessment_report);
	DTO_FIELD_INFO(is_assessment_report) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_assessment_report");
	}
	// Ӫҵִ�գ���֤��һ���Ƿ����
	DTO_FIELD(String, is_business_license);
	DTO_FIELD_INFO(is_business_license) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_business_license");
	}
	// Ԥ�����Ա������Ϣ�Ƿ����
	DTO_FIELD(String, is_person_info);
	DTO_FIELD_INFO(is_person_info) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_person_info");
	}
	// ��ͬ��ί���飩�Ƿ����
	DTO_FIELD(String, is_entrust_report);
	DTO_FIELD_INFO(is_entrust_report) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_entrust_report");
	}
	// ���������Ŀ�Ƿ��뱸��һ��
	DTO_FIELD(String, is_keep_record);
	DTO_FIELD_INFO(is_keep_record) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_keep_record");
	}
	// �����豸�Ƿ������ͬ��Э�飩����ְҵ�����������
	DTO_FIELD(String, is_equipment_true);
	DTO_FIELD_INFO(is_equipment_true) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_equipment_true");
	}
	// ί�е�λҪ���Ƿ���Ϲ����йط��ɡ����ߺͱ�׼�淶��Ҫ��
	DTO_FIELD(String, is_standard);
	DTO_FIELD_INFO(is_standard) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_standard");
	}
	// �Ƿ���ί�е�λ��������ʵ����Ч�Ĺ�ͨ���˽�ί�е�λ����ʵ����
	DTO_FIELD(String, is_understand_needs);
	DTO_FIELD_INFO(is_understand_needs) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_understand_needs");
	}
	// �Ƿ��漰��Ŀ�ְ�
	DTO_FIELD(String, is_subcontract);
	DTO_FIELD_INFO(is_subcontract) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_subcontract");
	}
	// ί�з������ʱ�䡢���������ر�Ҫ��
	DTO_FIELD(String, is_special_requirements);
	DTO_FIELD_INFO(is_special_requirements) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_special_requirements");
	}
	// �Ƿ��֪ί�з���췽�������ע������
	DTO_FIELD(String, is_inform);
	DTO_FIELD_INFO(is_inform) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_inform");
	}
	// �Ƿ�ί�з���ȡ
	DTO_FIELD(String, is_take_from_oneself);
	DTO_FIELD_INFO(is_take_from_oneself) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_take_from_oneself");
	}
	/**
	 ��ͬ��������
    **/
	// �Ƿ����Ϊί�е�λ�ṩְҵ����������
	DTO_FIELD(String, is_can_service);
	DTO_FIELD_INFO(is_can_service) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.is_can_service");
	}
	//  ����Ϊί�е�λ�ṩְҵ����������ԭ��
	DTO_FIELD(String, reason);
	DTO_FIELD_INFO(reason) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.reason");
	}
	// �ʿؿƸ����˻�������ĸ�����
	DTO_FIELD(String, conclusion_person_in_charge);
	DTO_FIELD_INFO(conclusion_person_in_charge) {
		info->description = ZH_WORDS_GETTER("groupapprove.field.conclusion_person_in_charge");
	}
};




#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUPAPPROVE_DTO_
