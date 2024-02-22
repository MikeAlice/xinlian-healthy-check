#pragma once
#ifndef _RULESLIST_DO_
#define _RULESLIST_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class RulesListDO
{
	// ID
	CC_SYNTHESIZE(std::string, id, Id);
	// name����
	CC_SYNTHESIZE(std::string, name, Name);
	// shortname���
	CC_SYNTHESIZE(std::string, short_name, Short_name);
	// type����
	CC_SYNTHESIZE(std::string, type, Type);
	// allowSex�ʺ��Ա�
	CC_SYNTHESIZE(std::string, allow_Sex, Allow_Sex);
	// baseProjectId��ĿID
	CC_SYNTHESIZE(std::string, base_project_id, Base_project_id);
	// careerAdviceְҵ����
	CC_SYNTHESIZE(std::string, career_advice, Caree_advice);
	// createId������
	CC_SYNTHESIZE(std::string, create_id, Create_id);
	// createTime����ʱ��
	CC_SYNTHESIZE(std::string, create_time, Create_time);
	// departmentId��������
	CC_SYNTHESIZE(std::string, department_id, Department_id);
	// dietaryGuidance��ʳָ��
	CC_SYNTHESIZE(std::string, dietary_guidance, Dietary_guidance);
	// healthAdvice��������
	CC_SYNTHESIZE(std::string, health_advice, Health_advice);
	// healthKnowledge����֪ʶ
	CC_SYNTHESIZE(std::string, health_knowledge, Health_knowledge);
	// inConclusion�Ƿ����С��
	CC_SYNTHESIZE(std::string, in_conclusion, In_conclusion);
	// intervalValue����ֵ
	CC_SYNTHESIZE(std::string, interval_value, Interval_value);
	// maxAge�������ֵ
	CC_SYNTHESIZE(int, max_Age, Max_Age);
	// minAge�������ֵ
	CC_SYNTHESIZE(int, min_Age, Min_Age);
	// positive�Ƿ�����
	CC_SYNTHESIZE(std::string, positive, Positive);
	// reminder��ܰ��ʾ
	CC_SYNTHESIZE(std::string, reminder, Reminder);
	// sportsGuidance�˶�ָ��
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
