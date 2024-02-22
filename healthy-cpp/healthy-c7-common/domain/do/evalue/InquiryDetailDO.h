#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: lenyan~
 @Date: 2024/1/27 

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
#ifndef _INQUIRYDETAIL_DO_
#define _INQUIRYDETAIL_DO_
#include "../DoInclude.h"

/**
 * 问诊明细数据库实体类
 */
class InquiryDetailDO
{
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 工龄年段
	CC_SYNTHESIZE(uint64_t, workYear, WorkYear);
	// 工龄月段
	CC_SYNTHESIZE(uint64_t, workMonth, WorkMonth);
	// 结婚状况
	CC_SYNTHESIZE(string, isMarry, IsMarry);
	//按需年龄
	CC_SYNTHESIZE(uint64_t, exposureWorkYear, ExposureWorkYear);
	//按需月龄
	CC_SYNTHESIZE(uint64_t, exposureWorkMonth, ExposureWorkMonth);

	//非必须
	
	//文化程度
	CC_SYNTHESIZE(string, education, Education);
	//家庭地址
	CC_SYNTHESIZE(string, familyAddress, FamilyAddress);
	//工种名称
	CC_SYNTHESIZE(string, workTypeText, WorkTypeText);
	//工种其他名称
	CC_SYNTHESIZE(string, workName, WorkName);
	//所属部门
	CC_SYNTHESIZE(string, department, Department);



public:
	InquiryDetailDO() {
		id = 1;
		workYear = 0;
		workMonth = 0;
		isMarry = "";
		exposureWorkYear = 0;
		exposureWorkMonth = 0;

		//非必须，可以为空
		education = "";
		familyAddress = "";
		workTypeText = "";
		workName = "";
		department = "";
	}
};

#endif // !_INQUIRYDETAIL_DO_

