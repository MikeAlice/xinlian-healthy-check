/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "GroupApproveController.h"
#include "../../service/groupapprove/GroupApproveService.h"
#include "../ApiDeclarativeServicesHelper.h"


Uint64JsonVO::Wrapper GroupApproveController::execAddGroupApprove(const GroupApproveDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->audit_level || !dto->is_info_table || dto->is_assessment_report || dto->is_business_license || dto->is_person_info ||
		dto->is_entrust_report || dto->is_keep_record || dto->is_equipment_true || dto->is_standard || dto->is_understand_needs ||
		dto->is_subcontract || dto->is_special_requirements || dto->is_inform || dto->is_take_from_oneself || dto->is_can_service ||
		dto->reason || dto->conclusion_person_in_charge
		)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->audit_level <0 || dto->is_info_table->empty() || dto->is_assessment_report->empty() || dto->is_business_license->empty() ||
		dto->is_person_info->empty() || dto->is_entrust_report->empty() || dto->is_keep_record->empty() || dto->is_equipment_true->empty() ||
		dto->is_standard->empty() || dto->is_understand_needs->empty() || dto->is_subcontract->empty() || dto->is_special_requirements->empty() ||
		dto->is_inform->empty() || dto->is_take_from_oneself->empty() || dto->is_can_service->empty() || dto->reason->empty() ||
		dto->conclusion_person_in_charge->empty()
		)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	GroupApproveService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}

Uint64JsonVO::Wrapper GroupApproveController::execModifyGroupApprove(const GroupApproveDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->id || dto->id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	GroupApproveService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
}

