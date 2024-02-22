#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _GROUPPERSON_DTO_
#define _GROUPPERSON_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 团检人员传输对象
 */
class GroupPersonDTO : public oatpp::DTO
{
	DTO_INIT(GroupPersonDTO, DTO);
	// 体检编号
	DTO_FIELD(String, testNum);
	DTO_FIELD_INFO(testNum) {
		info->description = ZH_WORDS_GETTER("exalanding.updateInformation.testNum");
	}
	// 人员姓名
	DTO_FIELD(String, personName);
	DTO_FIELD_INFO(personName) {
		info->description = ZH_WORDS_GETTER("exalanding.updateInformation.personName");
	}
	// 性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("exalanding.updateInformation.sex");
	}
	// 年龄
	DTO_FIELD(Int64, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("exalanding.updateInformation.age");
	}

	// 证件号码
	DTO_FIELD(String, idCard);
	DTO_FIELD_INFO(idCard) {
		info->description = ZH_WORDS_GETTER("exalanding.updateInformation.idCard");
	}

	// 是否结婚
	DTO_FIELD(String, isMarry);
	DTO_FIELD_INFO(isMarry) {
		info->description = ZH_WORDS_GETTER("exalanding.updateInformation.isMarry");
	}

	// 手机号码
	DTO_FIELD(String, mobile);
	DTO_FIELD_INFO(mobile) {
		info->description = ZH_WORDS_GETTER("exalanding.updateInformation.mobile");
	}

	// 体检人员工作部门（单位名称）
	DTO_FIELD(String, dept);
	DTO_FIELD_INFO(dept) {
		info->description = ZH_WORDS_GETTER("exalanding.updateInformation.workName");
	}

	// 体检类型
	DTO_FIELD(String, physicalType);
	DTO_FIELD_INFO(physicalType) {
		info->description = ZH_WORDS_GETTER("exalanding.updateInformation.physical");
	}
	// 分组id
	DTO_FIELD(String, groupId);
	DTO_FIELD_INFO(groupId) {
		info->description = ZH_WORDS_GETTER("exalanding.updateInformation.groupId");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GROUPPERSON_DTO_