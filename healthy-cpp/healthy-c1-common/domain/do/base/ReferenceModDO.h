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
#ifndef _REFERENCEMODDO_H_
#define _REFERENCEMODDO_H_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ReferenceModDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 适合性别
	CC_SYNTHESIZE(string, allowSex, AllowSex);
	// 年龄最低值
	CC_SYNTHESIZE(unsigned int, minAge, MinAge);
	// 年龄最高值
	CC_SYNTHESIZE(unsigned int, maxAge, MaxAge);
	// 健康参考值
	CC_SYNTHESIZE(string, healthyValue, HealthyValue);
	// 职业参考值
	CC_SYNTHESIZE(string, occupationValue, OccupationValue);
public:
	ReferenceModDO() {
		id = "";
		allowSex = "";
		
	}
};

#endif // !_REFERENCEMODDO_H_