#pragma once
#ifndef _RULESLIST_DO_
#define _RULESLIST_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class RulesListDO
{
	// ID
	CC_SYNTHESIZE(std::string, id, Id);
	// name名称
	CC_SYNTHESIZE(std::string, name, Name);
	// shortname简称
	CC_SYNTHESIZE(std::string, short_name, Short_name);
	// type类型
	CC_SYNTHESIZE(std::string, type, Type);
	// allowSex适合性别
	CC_SYNTHESIZE(std::string, allow_Sex, Allow_Sex);
	// baseProjectId项目ID
	CC_SYNTHESIZE(std::string, base_project_id, Base_project_id);
	// careerAdvice职业建议
	CC_SYNTHESIZE(std::string, career_advice, Caree_advice);
	// createId创建人
	CC_SYNTHESIZE(std::string, create_id, Create_id);
	// createTime创建时间
	CC_SYNTHESIZE(std::string, create_time, Create_time);
	// departmentId所属部门
	CC_SYNTHESIZE(std::string, department_id, Department_id);
	// dietaryGuidance饮食指导
	CC_SYNTHESIZE(std::string, dietary_guidance, Dietary_guidance);
	// healthAdvice健康建议
	CC_SYNTHESIZE(std::string, health_advice, Health_advice);
	// healthKnowledge健康知识
	CC_SYNTHESIZE(std::string, health_knowledge, Health_knowledge);
	// inConclusion是否进入小结
	CC_SYNTHESIZE(std::string, in_conclusion, In_conclusion);
	// intervalValue区间值
	CC_SYNTHESIZE(std::string, interval_value, Interval_value);
	// maxAge年龄最低值
	CC_SYNTHESIZE(int, max_Age, Max_Age);
	// minAge年龄最高值
	CC_SYNTHESIZE(int, min_Age, Min_Age);
	// positive是否阳性
	CC_SYNTHESIZE(std::string, positive, Positive);
	// reminder温馨提示
	CC_SYNTHESIZE(std::string, reminder, Reminder);
	// sportsGuidance运动指导
	CC_SYNTHESIZE(std::string, sports_guidance, Sports_guidance);
public:
	RulesListDO() {
		id = "";
		name="";
		short_name = "";
        type="";
		allow_Sex = "";
		base_project_id = "";
		career_advice = "";
		create_id = "";
		create_time = "";
		department_id = "";
		dietary_guidance = "";
		health_advice = "";
		health_knowledge = "";
		in_conclusion = "";
		interval_value = "";
		max_Age = 0;
		min_Age = 0;
		positive = "";
		reminder = "";
		sports_guidance = "";
	}
};

#endif // !_RULESLIST_DO_
