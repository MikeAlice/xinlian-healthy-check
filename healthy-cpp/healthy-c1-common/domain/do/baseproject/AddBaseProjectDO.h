#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: firmiana
 @Date: 2024/01/23
 @FileName: AddBaseProjectDO.h
 @version: 1.0

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
#ifndef _ADDBASEPROJECT_DO_H_
#define _ADDBASEPROJECT_DO_H_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class AddBaseProjectDO
{
	// id 主键
	//CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, id, Id);
	// code 项目代码
	CC_SYNTHESIZE(string, code, Code);
	// name 名称
	CC_SYNTHESIZE(string, name, Name);
	// short_name 简称
	CC_SYNTHESIZE(string, short_name, ShortName);
	// order_num 排序
	CC_SYNTHESIZE(float, order_num, OrderNum);
	// office_id 科室id
	CC_SYNTHESIZE(string, office_id, OfficeId);
	// office_name 科室名称
	CC_SYNTHESIZE(string, office_name, OfficeName);
	// unit_code 单位编码
	CC_SYNTHESIZE(string, unit_code, UnitCode);
	// unit_name 单位名称
	CC_SYNTHESIZE(string, unit_name, UnitName);
	// default_value 默认值
	CC_SYNTHESIZE(string, default_value, DefaultValue);
	// result_type 结果类型
	CC_SYNTHESIZE(string, result_type, ResultType);
	// in_conclusion 是否进入小结
	CC_SYNTHESIZE(string, in_conclusion, InConclusion);
	// in_report 是否进入报告
	CC_SYNTHESIZE(string, in_report, InReport);
	// relation_code LIS关联码
	CC_SYNTHESIZE(string, relation_code, RelationCode);
	// del_flag 是否删除(0-未删除，1-已删除)
	CC_SYNTHESIZE(unsigned int, del_flag, DelFlag);
	// create_id 创建人
	CC_SYNTHESIZE(string, create_id, CreateId);
	// create_time 创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
	// update_id 修改人
	CC_SYNTHESIZE(string, update_id, UpdateId);
	// update_time 修改时间
	CC_SYNTHESIZE(string, update_time, UpdateTime);
	// delete_id 删除人
	CC_SYNTHESIZE(string, delete_id, DeleteId);
	// delete_time 删除时间
	CC_SYNTHESIZE(string, delete_time, DeleteTime);
	// department_id 所属部门
	CC_SYNTHESIZE(string, department_id, DepartmentId);

public:
	AddBaseProjectDO() {
		id = "";
		code = "";
		name = "";
		short_name = "";
		office_id = "";
		office_name = "";
		unit_code = "";
		unit_name = "";
		default_value = "";
		result_type = "";
		in_conclusion = "";
		in_report = "";
		relation_code = "";
		create_id = "";
		create_time = "";
		update_id = "";
		update_time = "";
		delete_id = "";
		delete_time = "";
		department_id = "";

		order_num = 1;
		del_flag = 0;
	}

};

#endif // !_ADDBASEPROJECT_DO_H_
