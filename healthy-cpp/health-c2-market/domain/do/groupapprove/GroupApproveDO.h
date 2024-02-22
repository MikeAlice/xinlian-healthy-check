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
 * 示例数据库实体类
 */
class GroupApproveDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 评审级别
	CC_SYNTHESIZE(uint64_t, audit_level, Audit_level);
	// 用人单位基本情况信息表是否存在
	CC_SYNTHESIZE(string, is_info_table, Is_info_table);
	// 近期职业病危害因素检测报告或评价报告是否存在
	CC_SYNTHESIZE(string, is_assessment_report, Is_assessment_report);
	// 营业执照（三证合一）是否存在
	CC_SYNTHESIZE(string, is_business_license, Is_business_license);
	// 预体检人员名单信息是否存在
	CC_SYNTHESIZE(string, is_person_info, Is_person_info);
	// 合同（委托书）是否存在
	CC_SYNTHESIZE(string, is_entrust_report, Is_entrust_report);
	// 检查类别和项目是否与备案一致
	CC_SYNTHESIZE(string, is_keep_record, Is_keep_record);
	// 仪器设备是否满足合同（协议）所订职业健康检查需求
	CC_SYNTHESIZE(string, is_equipment_true, Is_equipment_true);
	// 委托单位要求是否符合国家有关法律、政策和标准规范的要求
	CC_SYNTHESIZE(string, is_standard, Is_standard);
	// 是否与委托单位进行了真实而有效的沟通，了解委托单位的真实需求
	CC_SYNTHESIZE(string, is_understand_needs, Is_understand_needs);
	// 是否涉及项目分包
	CC_SYNTHESIZE(string, is_subcontract, Is_subcontract);
	// 委托方对体检时间、期限有无特别要求
	CC_SYNTHESIZE(string, is_special_requirements, Is_special_requirements);
	// 是否告知委托方体检方案及体检注意事项
	CC_SYNTHESIZE(string, is_inform, Is_inform);
	// 是否委托方自取
	CC_SYNTHESIZE(string, is_take_from_oneself, Is_take_from_oneself);
	// 是否可以为委托单位提供职业健康检查服务
	CC_SYNTHESIZE(string, is_can_service, Is_can_service);
	// 不能为委托单位提供职业健康检查服务，原因
	CC_SYNTHESIZE(string, reason, Reason);
	// 质控科负责人或体检中心负责人
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
