/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/01/27 20:39:00

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
#ifndef _UNITREPORTDO_H_
#define _UNITREPORTDO_H_

#include "../DoInclude.h"

class UnitReportDO
{
	// 报告编号
	CC_SYNTHESIZE(string, code, CCode)
	// 体检单位
	CC_SYNTHESIZE(string, physical_unit, PhysicalUnit)
	// 体检日期
	CC_SYNTHESIZE(string, physical_date, PhysicalDate)
	// 体检项目
	CC_SYNTHESIZE(string, physical_project, PhysicalProject)
	// 体检意见
	CC_SYNTHESIZE(string, concluding_observations, ConcludingObservations)
	// 体检类型
	CC_SYNTHESIZE(string, physical_type, PhysicalType)
	// 委托单位
	CC_SYNTHESIZE(string, entrust_unit, EntrustUnit)
	// 体检人数
	CC_SYNTHESIZE(string, physical_number, PhysicalNumber)
	// 评论依据
	CC_SYNTHESIZE(string, evaluation_basis, EvaluationBasis)
};

#endif // !_UNITREPORTDO_H_