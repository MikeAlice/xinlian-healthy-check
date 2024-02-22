#ifndef _REPORTPREVIEW_DO_
#define _REPORTPREVIEW_DO_
#include "../DoInclude.h"

/*
* 报告预览数据库实体类
*/
class ReportPreviewDO
{
	//人员姓名
	CC_SYNTHESIZE(string, person_name, Person_name);
	//t_group_person
	//性别
	CC_SYNTHESIZE(string, sex, Sex);
	//证件号码
	CC_SYNTHESIZE(string, id_card, Id_card);
	//出生日期
	CC_SYNTHESIZE(string, birth, Birth);
	//年龄
	CC_SYNTHESIZE(int, age, Age);
	//家庭住址
	CC_SYNTHESIZE(string, home_address, Home_address);
	//手机号码
	CC_SYNTHESIZE(string, mobile, Mobile);
	//体检编号
	CC_SYNTHESIZE(string, test_num, Test_num);
	// 所属部门
	CC_SYNTHESIZE(string, department, Department);
	//体检人员工作部门(单位名称)
	CC_SYNTHESIZE(string, dept, Dept);
	//体检日期
	CC_SYNTHESIZE(string, check_date, Check_date);
	//危害因素名称
	CC_SYNTHESIZE(string, other_hazard_factors, Other_hazard_factors);
	//工种名称
	CC_SYNTHESIZE(string, work_type_text, Work_type_text);
	//t_interrogation
	// 总工龄年数
	CC_SYNTHESIZE(int, work_year, Work_year);
	// 接害工龄年数
	CC_SYNTHESIZE(int, exposure_work_year, Exposure_work_year);
	// 文化程度
	CC_SYNTHESIZE(string, education, Education);
	// 婚姻史-结婚日期
	CC_SYNTHESIZE(string, marriage_date, Marriage_date);
	// 月经状态（经期，周期）
	CC_SYNTHESIZE(int, period, Period);
	CC_SYNTHESIZE(int, cycle, Cycle);
	// 初潮
	CC_SYNTHESIZE(int, menarche, Menarche);
	//末次月经/停经年龄
	CC_SYNTHESIZE(string, last_menstruation, Last_menstruation);
	// 现有子女
	CC_SYNTHESIZE(string, existing_children, Existing_children);
	// 流产
	CC_SYNTHESIZE(string, abortion, Abortion);
	// 早产
	CC_SYNTHESIZE(string, premature, Premature);
	// 死亡
	CC_SYNTHESIZE(string, death, Death);
	// 异常胎
	CC_SYNTHESIZE(string, abnormal_fetus, Abnormal_fetus);
	// 过敏史
	CC_SYNTHESIZE(string, allergies, Allergies);
	// 包每天
	CC_SYNTHESIZE(int, package_every_day, Package_every_day);
	// 吸烟年
	CC_SYNTHESIZE(int, smoke_year, Smoke_year);
	// ml每天
	CC_SYNTHESIZE(int, ml_every_day, Ml_every_day);
	// 喝酒年
	CC_SYNTHESIZE(int, drink_year, Drink_year);
	// 出生地名称
	CC_SYNTHESIZE(string, birthplace_name, Birthplace_name);
	// 家族史
	CC_SYNTHESIZE(string, family_history, Family_history);
	// 既往病史其他信息
	CC_SYNTHESIZE(string, past_medical_history, Past_medical_history);
	// 病名
	CC_SYNTHESIZE(string, disease_name, Disease_name);

public:
	ReportPreviewDO() {

	}
};
/*
* 个人症状询问数据库实体类
*/
class T_symptomDO {

	//t_symptom
	// 程度
	CC_SYNTHESIZE(string, degree, Degree);
	// 时间
	CC_SYNTHESIZE(string, course_time, Course_time);
	//项目名称
	CC_SYNTHESIZE(string, project_name, Project_name);
public:
	T_symptomDO() {

	}
};

#endif // !_REPORTPREVIEW_DO_
