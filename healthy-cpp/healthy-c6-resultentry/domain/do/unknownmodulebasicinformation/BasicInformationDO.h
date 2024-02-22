#pragma once
#ifndef _BASICINFORMATIONCONTROLLER_DO_
#define _BASICINFORMATIONCONTROLLER_DO_
#include "../DoInclude.h"

class BasicInformationDO
{
	// 唯一编号
	CC_SYNTHESIZE(string, person_id, Person_id);
	// 特殊工种名称
	CC_SYNTHESIZE(string, job, Job);
	// 工龄年数
	CC_SYNTHESIZE(int, work_year, Work_year);
	// 工龄月数
	CC_SYNTHESIZE(int, work_month, Work_month);
	// 接害开始时间
	CC_SYNTHESIZE(string, exposure_start_date, Exposure_start_date);
	// 文化程度
	CC_SYNTHESIZE(string, education, Education);
	// 家庭住址
	CC_SYNTHESIZE(string, family_address, Family_address);
	// 婚姻状况
	CC_SYNTHESIZE(string, marriage_date, Marriage_date);

public:
	BasicInformationDO() {
		person_id = "";
		job = "";
		work_year = -1;
		work_month = -1;
		exposure_start_date = "";
		education = "";
		family_address = "";
		marriage_date = "";
	}
};

#endif // !_GroupPerson_DO_
