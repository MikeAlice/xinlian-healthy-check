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
#ifndef _UPDATEINFORMATIONDO_H_
#define _UPDATEINFORMATIONDO_H_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class UpdateInformationDO
{
	// 人员姓名
	CC_SYNTHESIZE(string, personName, PersonName);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(uint64_t, age, Age);
	// 结婚状况
	CC_SYNTHESIZE(string, isMarry, IsMarry);
	// 证件号码
	CC_SYNTHESIZE(string, idCard, IdCard);
	// 出生日期
	CC_SYNTHESIZE(string, birth, Birth);
	// 分组
	CC_SYNTHESIZE(string, groupId, GroupId);
	// 单位名称
	CC_SYNTHESIZE(string, workName, WorkName);
	// 手机号码
	CC_SYNTHESIZE(string, mobile, Mobile);


public:
	UpdateInformationDO() {
		personName = "";
		sex = "";
		age = -1;
		isMarry = "";
		idCard = "";
		birth = "";
		groupId = "";
		workName = "";
		mobile = "";
	}
};

#endif // !_UPDATEINFORMATIONDO_H_
