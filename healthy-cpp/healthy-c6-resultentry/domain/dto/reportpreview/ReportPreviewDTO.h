#ifndef _REPORTPREVIEW_DTO_
#define _REPORTPREVIEW_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* 报告预览传输对象
*/
class ReportPreviewViewDTO :public oatpp::DTO
{
	DTO_INIT(ReportPreviewViewDTO, DTO);
	//人员姓名
	DTO_FIELD(String, person_name);
	DTO_FIELD_INFO(person_name) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.person_name");
	}
	//t_group_person
	//性别
	DTO_FIELD(String, sex);
	DTO_FIELD_INFO(sex) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.sex");
	}
	//证件号码
	DTO_FIELD(String, id_card);
	DTO_FIELD_INFO(id_card) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.id_card");
	}
	//出生日期
	DTO_FIELD(String, birth);
	DTO_FIELD_INFO(birth) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.birth");
	}
	//年龄
	DTO_FIELD(UInt64, age);
	DTO_FIELD_INFO(age) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.age");
	}
	//家庭住址
	DTO_FIELD(String, home_address);
	DTO_FIELD_INFO(home_address) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.home_address");
	}
	//手机号码
	DTO_FIELD(String, mobile);
	DTO_FIELD_INFO(mobile) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.mobile");
	}
	//体检编号
	DTO_FIELD(String, test_num);
	DTO_FIELD_INFO(test_num) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.test_num");
	}
	// 所属部门
	DTO_FIELD(String, department);
	DTO_FIELD_INFO(department) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.department");
	}
	//体检人员工作部门(单位名称)
	DTO_FIELD(String, dept);
	DTO_FIELD_INFO(dept) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.dept");
	}
	//体检日期
	DTO_FIELD(String, check_date);
	DTO_FIELD_INFO(check_date) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.check_date");
	}
	//危害因素名称
	DTO_FIELD(String, other_hazard_factors);
	DTO_FIELD_INFO(other_hazard_factors) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.other_hazard_factors");
	}
	//工种名称
	DTO_FIELD(String, work_type_text);
	DTO_FIELD_INFO(work_type_text) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.work_type_text");
	}
	//t_interrogation
	// 总工龄年数
	DTO_FIELD(UInt64, work_year);
	DTO_FIELD_INFO(work_year) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.work_year");
	}
	// 接害工龄年数
	DTO_FIELD(UInt64, exposure_work_year);
	DTO_FIELD_INFO(exposure_work_year) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.exposure_work_year");
	}
	// 文化程度
	DTO_FIELD(String, education);
	DTO_FIELD_INFO(education) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.education");
	}
	// 婚姻史-结婚日期
	DTO_FIELD(String, marriage_date);
	DTO_FIELD_INFO(marriage_date) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.marriage_date");
	}
	// 月经状态（经期，周期）
	DTO_FIELD(UInt64, period);
	DTO_FIELD_INFO(period) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.period");
	}
	DTO_FIELD(UInt64, cycle);
	DTO_FIELD_INFO(cycle) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.cycle");
	}
	// 初潮
	DTO_FIELD(UInt64, menarche);
	DTO_FIELD_INFO(menarche) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.menarche");
	}
	//末次月经/停经年龄
	DTO_FIELD(String, last_menstruation);
	DTO_FIELD_INFO(last_menstruation) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.last_menstruation");
	}
	// 现有子女
	DTO_FIELD(String, existing_children);
	DTO_FIELD_INFO(existing_children) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.existing_children");
	}
	// 流产
	DTO_FIELD(String, abortion);
	DTO_FIELD_INFO(abortion) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.abortion");
	}
	// 早产
	DTO_FIELD(String, premature);
	DTO_FIELD_INFO(premature) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.premature");
	}
	// 死亡
	DTO_FIELD(String, death);
	DTO_FIELD_INFO(death) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.death");
	}
	// 异常胎
	DTO_FIELD(String, abnormal_fetus);
	DTO_FIELD_INFO(abnormal_fetus) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.abnormal_fetus");
	}
	// 过敏史
	DTO_FIELD(String, allergies);
	DTO_FIELD_INFO(allergies) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.allergies");
	}
	// 包每天
	DTO_FIELD(UInt64, package_every_day);
	DTO_FIELD_INFO(package_every_day) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.package_every_day");
	}
	// 吸烟年
	DTO_FIELD(UInt64, smoke_year);
	DTO_FIELD_INFO(smoke_year) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.smoke_year");
	}
	// ml每天
	DTO_FIELD(UInt64, ml_every_day);
	DTO_FIELD_INFO(ml_every_day) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.ml_every_day");
	}
	// 喝酒年
	DTO_FIELD(UInt64, drink_year);
	DTO_FIELD_INFO(drink_year) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.drink_year");
	}
	// 出生地名称
	DTO_FIELD(String, birthplace_name);
	DTO_FIELD_INFO(birthplace_name) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.birthplace_name");
	}
	// 家族史
	DTO_FIELD(String, family_history);
	DTO_FIELD_INFO(family_history) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.family_history");
	}
	// 既往病史其他信息
	DTO_FIELD(String, past_medical_history);
	DTO_FIELD_INFO(past_medical_history) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.past_medical_history");
	}
	// 病名
	DTO_FIELD(String, disease_name);
	DTO_FIELD_INFO(disease_name) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.disease_name");
	}
};
/*
* 症状询问传输对象
*/
class T_symptomDTO :public oatpp::DTO {
	DTO_INIT(T_symptomDTO, DTO);
	// 程度
	DTO_FIELD(String, degree);
	DTO_FIELD_INFO(degree) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.degree");
	}
	// 时间
	DTO_FIELD(String, course_time);
	DTO_FIELD_INFO(course_time) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.course_time");
	}
	//项目名称
	DTO_FIELD(String, project_name);
	DTO_FIELD_INFO(project_name) {
		info->description = ZH_WORDS_GETTER("reportpreview.file.project_name");
	}

};
#include OATPP_CODEGEN_END(DTO)
#endif // !_REPORTPREVIEW_DTO_
