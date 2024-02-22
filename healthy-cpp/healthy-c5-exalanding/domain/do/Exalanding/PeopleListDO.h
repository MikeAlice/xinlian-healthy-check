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
#ifndef _PEOPLELIST_DO_
#define _PEOPLELIST_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class PeopleListDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, person_name, Person_name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// 检测类型
	CC_SYNTHESIZE(string, jc_type, Jc_type);
	// 是否零星体检
	CC_SYNTHESIZE(string, sporadic_physical, Sporadic_physical);
public:
	PeopleListDO() {
		id = "";
		person_name = "";
		sex = "";
		age = -1;
		jc_type = "";
		sporadic_physical = "";
	}
};

#endif // !_SAMPLE_DO_