#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: smartPiggy
 @Date: 2024-01-26

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
#ifndef _RESULTDO_H_
#define _RESULTDO_H_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ResultDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 科室
	CC_SYNTHESIZE(string, officeName, OfficeName);
	// 组合项目
	CC_SYNTHESIZE(string, groupItemName, GroupItemName);
	// 体检小结
	CC_SYNTHESIZE(string, diagnoseSum, DiagnoseSum);
public:
	ResultDO() {
		id = "0";
		officeName = " ";
		groupItemName = " ";
		diagnoseSum = " ";
	}
	
};

#endif // !_RESULTDO_H_
