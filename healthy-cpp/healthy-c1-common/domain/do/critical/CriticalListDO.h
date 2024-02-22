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
#ifndef _CRITICAL_LIST_DO_
#define _CRITICAL_LIST_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class CriticalListDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, level, Level);
	CC_SYNTHESIZE(string, type, Type);
	CC_SYNTHESIZE(string, intervalValue, IntervalValue);
	CC_SYNTHESIZE(string, allowSex, AllowSex);
	CC_SYNTHESIZE(uint32_t, minAge, MinAge);
	CC_SYNTHESIZE(uint32_t, maxAge, MaxAge);
public:
	CriticalListDO() 
	{
		id = "";
		level = "";
		type = "";
		intervalValue = "";
		allowSex = "";
		minAge = 0;
		maxAge = 0;
	}
};

#endif // !_SAMPLE_DO_

