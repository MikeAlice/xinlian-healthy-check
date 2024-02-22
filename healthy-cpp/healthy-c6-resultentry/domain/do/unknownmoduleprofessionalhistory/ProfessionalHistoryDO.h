#pragma once
#ifndef _PROFESSIONALHISTORYCONTRONLLER_DO_
#define _PROFESSIONALHISTORYCONTRONLLER_DO_
#include "../DoInclude.h"

class ProfessionalHistoryDO
{
	// 唯一编号
	CC_SYNTHESIZE(string, person_id, Person_id);
	// 起始时间
	CC_SYNTHESIZE(string, start_date, Start_date);
	// 结束时间
	CC_SYNTHESIZE(string, end_date, End_date);
	// 工作单位
	CC_SYNTHESIZE(string, work_unit, Work_unit);
	// 车间（部门）
	CC_SYNTHESIZE(string, department, Department);
	// 工种
	CC_SYNTHESIZE(string, work_type_text, Work_type_text);
	// 危害因素
	CC_SYNTHESIZE(string, hazard_factors_text, Hazard_factors_text);
	// 防护措施
	CC_SYNTHESIZE(string, protective_measures, Protective_measures);
	// 接触时间
	CC_SYNTHESIZE(string, contact_time, Contact_time);

public:
	ProfessionalHistoryDO() {
		person_id = "";
		start_date = "";
		end_date = "";
		work_unit = "";
		department = "";
		work_type_text = "";
		hazard_factors_text = "";
		protective_measures = "";
		contact_time = "";
	}
};

#endif // !_GroupPerson_DO_
