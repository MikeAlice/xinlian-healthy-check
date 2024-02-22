#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: DY
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
#ifndef _REPORT_DO_
#define _REPORT_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class ReportDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(uint32_t, age, Age);
	// 身份证号
	CC_SYNTHESIZE(string, idCard, IdCard);
	// 联系电话
	CC_SYNTHESIZE(string, mobile, Mobile);
	// 体检类型
	CC_SYNTHESIZE(string, physicalType, PhysicalType);
	// 工作单位
	CC_SYNTHESIZE(string, dept, Dept);
	// 结论
	CC_SYNTHESIZE(string, conclusion, Conclusion);
	// 处理意见
	CC_SYNTHESIZE(string, handleOpinion, HandleOpinion);
	// 主检医生
	CC_SYNTHESIZE(string, inspectionDoctor, InspectionDoctor);
	// 体检日期
	CC_SYNTHESIZE(string, inspectionDate, InspectionDate);
	// 体检单位
	CC_SYNTHESIZE(string, diagnosticUnit, DiagnosticUnit);
	// PDF地址
	CC_SYNTHESIZE(string, href, Href);

public:
	ReportDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
		idCard = "";
		mobile = "";
		physicalType = "";
		dept = "";
		conclusion = "";
		handleOpinion = "";
		inspectionDoctor = "";
		inspectionDate = "";
		diagnosticUnit = "";
		href = "2";
	}
};

#endif // !_REPORT_DO_
