#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2024/01/14
 @FileName: QueryRefValueDO
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
#ifndef _QUERY_REF_VALUE_DO_
#define _QUERY_REF_VALUE_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class QueryRefValueDO
{
	// ����
	CC_SYNTHESIZE(string, id, Id);
	// ��Ŀid
	CC_SYNTHESIZE(string, base_project_id, BaseProjectId);
	// �ʺ��Ա�
	CC_SYNTHESIZE(string, allow_sex, AllowSex);
	// �������ֵ
	CC_SYNTHESIZE(int64_t, min_age, MinAge);
	// �������ֵ
	CC_SYNTHESIZE(int64_t, max_age, MaxAge);
	// �����ο�ֵ
	CC_SYNTHESIZE(string, healthy_value, HealthyValue);
	// ְҵ�ο�ֵ
	CC_SYNTHESIZE(string, occupation_value, OccupationValue);
	// ��������
	CC_SYNTHESIZE(string, department_id, DepartmentId);
	// ������
	CC_SYNTHESIZE(string, create_id, CreateId);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, CreateTime);
public:
	QueryRefValueDO()
	{
		base_project_id = "";
		allow_sex = "";
		min_age = 0;
		max_age = 0;
		healthy_value = "";
		occupation_value = "";
		department_id = "";
		create_id = "";
		create_time = "";
	}
};
#endif