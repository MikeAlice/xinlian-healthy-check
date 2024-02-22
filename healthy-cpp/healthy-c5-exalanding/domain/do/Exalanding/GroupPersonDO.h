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
#ifndef _GROUPPERSON_DO_
#define _GROUPPERSON_DO_
#include "../DoInclude.h"

/**
 * 团检人员数据库实体类
 */
class GroupPersonDO
{
	// 编号
	CC_SYNTHESIZE(string, testNum, TestNum);
	// 姓名
	CC_SYNTHESIZE(string, personName, PersonName);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 证件号码
	CC_SYNTHESIZE(string, idCard, IdCard);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// 是否结婚
	CC_SYNTHESIZE(string, isMarry, IsMarry);
	// 手机号码
	CC_SYNTHESIZE(string, mobile, Mobile);
	// 体检人员工作部门（单位名称）
	CC_SYNTHESIZE(string, dept, Dept);
	// 体检类型
	CC_SYNTHESIZE(string, physicalType, PhysicalType);
	// 分组id
	CC_SYNTHESIZE(string, groupId, GroupId);
public:
	GroupPersonDO() {
		testNum = "0000000000000";
		personName = "xxx";
		sex = "";
		idCard = "";
		age = 22;
		isMarry = "";
		mobile = "";
		dept = "";
		physicalType = "";
		groupId = "";
	}
};

#endif // !_GROUPPERSON_DO_