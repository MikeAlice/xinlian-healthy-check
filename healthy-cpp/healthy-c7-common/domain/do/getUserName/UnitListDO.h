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
#ifndef _UnitList_DO_
#define _UnitList_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class UnitListDO
{
	//体检类型
	CC_SYNTHESIZE(int, ispass, Ispass);
	// 复查状态  复查人员在复检人员信息表中查询
	CC_SYNTHESIZE(int, isRecheck, IsRecheck);
	//开始时间
	CC_SYNTHESIZE(string, startDate, StartDate);
	//结束时间
	CC_SYNTHESIZE(string, endDate, EndDate);
	//体检编号
	CC_SYNTHESIZE(string, testNum, TestNum);
	//单位名称
	CC_SYNTHESIZE(string, dept, Dept);


	// 姓名
	CC_SYNTHESIZE(string, personName, PersonName);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// 体检类型 physicalType
	CC_SYNTHESIZE(string, physicalType, PhysicalType);
	// 是否零星体检(0-否，1-是)
	CC_SYNTHESIZE(int, sporadicPhysical, SporadicPhysical);//int类型可能有点小问题

public:
	UnitListDO() {
		ispass = 1;
		isRecheck = 0;
		startDate = "";
		endDate = "";
		testNum = "";
		dept = "";

		personName = "";
		sex = "";
		age = -1;
		physicalType = "";
		sporadicPhysical = 0;
	}
};

#endif // !_SAMPLE_DO_
