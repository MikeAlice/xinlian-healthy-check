#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2024/01/14
 @FileName: RefValueDO
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
#ifndef _REF_VALUE_DO_
#define _REF_VALUE_DO_
#include "../DoInclude.h"

/**
 * 基础项目配置（参考值）数据库实体类
 */
class RefValueDO
{
	// 主键
	CC_SYNTHESIZE(string, id, Id);
	// 项目id
	CC_SYNTHESIZE(string, base_project_id, BaseProjectId);
	// 适合性别
	CC_SYNTHESIZE(string, allow_sex, AllowSex);
	// 年龄最低值
	CC_SYNTHESIZE(int64_t, min_age, MinAge);
	// 年龄最高值
	CC_SYNTHESIZE(int64_t, max_age, MaxAge);
	// 健康参考值
	CC_SYNTHESIZE(string, healthy_value, HealthyValue);
	// 职业参考值
	CC_SYNTHESIZE(string, occupation_value, OccupationValue);
	// 所属部门
	CC_SYNTHESIZE(string, department_id, DepartmentId);
	// 创建人
	CC_SYNTHESIZE(string, create_id, CreateId);
	// 创建时间
	CC_SYNTHESIZE(string, create_time, CreateTime);
public:
	
};
#endif