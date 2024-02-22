#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: stoner
 @Date: 2024/1/25 11:52:32

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
#ifndef _QUERY_CRIT_VALUE_DO_
#define _QUERY_CRIT_VALUE_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class QueryCritValueDO
{
	// id
	CC_SYNTHESIZE(string, id, Id);
	// base_project_id 项目id
	CC_SYNTHESIZE(string, baseProjectId, BaseProjectId);
	//level 等级
	CC_SYNTHESIZE(string, level, Level);
	//type 类型
	CC_SYNTHESIZE(string, type, Type);
	//interval_value 区间值
	CC_SYNTHESIZE(string, intervalValue, IntervalValue);
	// allow_sex 适合性别
	CC_SYNTHESIZE(string, allowSex, AllowSex);
	// min_age 年龄最低值
	CC_SYNTHESIZE(int64_t, minAge, MinAge);
	// max_age 年龄最高值
	CC_SYNTHESIZE(int64_t, maxAge, MaxAge);
	// department_id 所属部门
	CC_SYNTHESIZE(string, departmentId, DepartmentId);
	// create_id 创建人
	CC_SYNTHESIZE(string, createId, CreateId);
	// create_time 创建时间
	CC_SYNTHESIZE(string, createTime, CreateTime);
public:
	QueryCritValueDO()
	{
		id = "";
		baseProjectId = "";
		level = "";
		type = "";
		intervalValue = "";
		allowSex = "";
		minAge = 0;
		maxAge = 0;
		departmentId = "";
		createId = "";
		createTime = "";
	}
};

#endif 