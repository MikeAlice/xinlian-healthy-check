#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 会跑的鱼
 @Date: 2024/1/19 17:36:29

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
#ifndef _RESULTSLIST_DO_
#define _RESULTSLIST_DO_
#include "../DoInclude.h"

/**
 * 体检结论数据库实体类
 */
class ResultsListDO
{
	// 体检编号
	CC_SYNTHESIZE(string, test_num, CheckId);
	// 姓名
	CC_SYNTHESIZE(string, person_name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// ID
	CC_SYNTHESIZE(string, id, Id);
	//身份证号
	CC_SYNTHESIZE(string, id_card, IdCard);
	//体检状态
	//CC_SYNTHESIZE(string, check_status, CheckState);
	CC_SYNTHESIZE(string, statu, CheckState);
	//在岗状态
	CC_SYNTHESIZE(string, work_state_text, DutyState);
	//危害因素
	CC_SYNTHESIZE(string, hazard_factors_text, DangerFactors);
	//体检日期
	CC_SYNTHESIZE(string, check_date, CheckDate);
	//体检结论
	CC_SYNTHESIZE(string, comments, CheckResults);

	////未完成项目
	//CC_SYNTHESIZE(string, comments, checkResults);
	//DTO_FIELD(String, unfinishedProject);
	//DTO_FIELD_INFO(unfinishedProject) {
	//	info->description = ZH_WORDS_GETTER("results.field.unfinishedProject");
	//}
	
	//单位名称
	CC_SYNTHESIZE(string, unit_name, unitName);
	//审核状态/
	CC_SYNTHESIZE(int32_t, audit_state, State);
	

public:
	ResultsListDO() {
		test_num = "";
		person_name = "";
		sex = "";
		age = -1;
		id_card = "";
		statu = "";
		work_state_text = "";
		hazard_factors_text = "";
		check_date = "";
		comments = "";
		unit_name = "";
		audit_state = 0;
	}
};

#endif // !_RESULTSLIST_DO_
