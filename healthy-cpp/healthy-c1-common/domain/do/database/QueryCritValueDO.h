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
 * ʾ�����ݿ�ʵ����
 */
class QueryCritValueDO
{
	// id
	CC_SYNTHESIZE(string, id, Id);
	// base_project_id ��Ŀid
	CC_SYNTHESIZE(string, baseProjectId, BaseProjectId);
	//level �ȼ�
	CC_SYNTHESIZE(string, level, Level);
	//type ����
	CC_SYNTHESIZE(string, type, Type);
	//interval_value ����ֵ
	CC_SYNTHESIZE(string, intervalValue, IntervalValue);
	// allow_sex �ʺ��Ա�
	CC_SYNTHESIZE(string, allowSex, AllowSex);
	// min_age �������ֵ
	CC_SYNTHESIZE(int64_t, minAge, MinAge);
	// max_age �������ֵ
	CC_SYNTHESIZE(int64_t, maxAge, MaxAge);
	// department_id ��������
	CC_SYNTHESIZE(string, departmentId, DepartmentId);
	// create_id ������
	CC_SYNTHESIZE(string, createId, CreateId);
	// create_time ����ʱ��
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