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
#ifndef _INFO_LIST_DO_
#define _INFO_LIST_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class InfoListDO
{
	CC_SYNTHESIZE(int, id, Id);
	//体检人员
	CC_SYNTHESIZE(int, personId, PersonId);
	//总检医生
	CC_SYNTHESIZE(string, inspectionDoctor, InspectionDoctor);
	//总检日期
	CC_SYNTHESIZE(string, inspectionDate, InspectionDate);
	//医学建议
	CC_SYNTHESIZE(string, medicalAdvice, MedicalAdvice);
	//处理意见
	CC_SYNTHESIZE(string, handleOpinion, HandleOpinion);

public:
	InfoListDO() {
		personId = 0;
		inspectionDoctor = "";
		inspectionDate = "";
		medicalAdvice = "";
		handleOpinion = "";
	}
};

#endif // !_SAMPLE_DO_
