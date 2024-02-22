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
#ifndef _CLABANPROJDO_H_
#define _CLABANPROJDO_H_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ClAbanProjDO
{
	// 人员id
	CC_SYNTHESIZE(string, personId, PersonId);
	// 科室id
	CC_SYNTHESIZE(string, officeId, OfficeId);
	// 分组项目id
	CC_SYNTHESIZE(string, orderGroupItemId, OrderGroupItemId);
public:
	ClAbanProjDO() {
		personId = "";
		officeId = "";
		orderGroupItemId = "";
	}
};

#endif // !_CLABANPROJDO_H_
