#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _GROUPAPPROVE_DO_
#define _GROUPAPPROVE_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class GroupApproveDO
{
	// ���
	CC_SYNTHESIZE(uint64_t, id, Id);
	// ���󼶱�
	CC_SYNTHESIZE(uint64_t, audit_level, Audit_level);
	// ���˵�λ���������Ϣ���Ƿ����
	CC_SYNTHESIZE(string, is_info_table, Is_info_table);
	// ����ְҵ��Σ�����ؼ�ⱨ������۱����Ƿ����
	CC_SYNTHESIZE(string, is_assessment_report, Is_assessment_report);
	// Ӫҵִ�գ���֤��һ���Ƿ����
	CC_SYNTHESIZE(string, is_business_license, Is_business_license);
	// Ԥ�����Ա������Ϣ�Ƿ����
	CC_SYNTHESIZE(string, is_person_info, Is_person_info);
	// ��ͬ��ί���飩�Ƿ����
	CC_SYNTHESIZE(string, is_entrust_report, Is_entrust_report);
	// ���������Ŀ�Ƿ��뱸��һ��
	CC_SYNTHESIZE(string, is_keep_record, Is_keep_record);
	// �����豸�Ƿ������ͬ��Э�飩����ְҵ�����������
	CC_SYNTHESIZE(string, is_equipment_true, Is_equipment_true);
	// ί�е�λҪ���Ƿ���Ϲ����йط��ɡ����ߺͱ�׼�淶��Ҫ��
	CC_SYNTHESIZE(string, is_standard, Is_standard);
	// �Ƿ���ί�е�λ��������ʵ����Ч�Ĺ�ͨ���˽�ί�е�λ����ʵ����
	CC_SYNTHESIZE(string, is_understand_needs, Is_understand_needs);
	// �Ƿ��漰��Ŀ�ְ�
	CC_SYNTHESIZE(string, is_subcontract, Is_subcontract);
	// ί�з������ʱ�䡢���������ر�Ҫ��
	CC_SYNTHESIZE(string, is_special_requirements, Is_special_requirements);
	// �Ƿ��֪ί�з���췽�������ע������
	CC_SYNTHESIZE(string, is_inform, Is_inform);
	// �Ƿ�ί�з���ȡ
	CC_SYNTHESIZE(string, is_take_from_oneself, Is_take_from_oneself);
	// �Ƿ����Ϊί�е�λ�ṩְҵ����������
	CC_SYNTHESIZE(string, is_can_service, Is_can_service);
	// ����Ϊί�е�λ�ṩְҵ����������ԭ��
	CC_SYNTHESIZE(string, reason, Reason);
	// �ʿؿƸ����˻�������ĸ�����
	CC_SYNTHESIZE(string, conclusion_person_in_charge, Conclusion_person_in_charge);

public:
	GroupApproveDO() {
		id = 0;
		audit_level = 0;
		is_info_table = "";
		is_assessment_report = "";
		is_business_license = "";
		is_person_info = "";
		is_entrust_report = "";
		is_keep_record = "";
		is_equipment_true = "";
		is_standard = "";
		is_understand_needs = "";
		is_subcontract = "";
		is_special_requirements = "";
		is_inform = "";
		is_take_from_oneself = "";
		is_can_service = "";
		reason = "";
		conclusion_person_in_charge = "";
	}
};

#endif // !_GROUPAPPROVE_DO_
