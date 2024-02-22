#include "stdafx.h"
#include "ReportPreviewDAO.h"
#include"ReportPreviewMapper.h"
list<ReportPreviewDO> ReportPreviewDAO::queryReportPreview(const string& person_id, const string& person_name)
{
	string sql = "SELECT tgp.person_name,tgp.sex,tgp.id_card,tgp.birth,tgp.age,tgp.home_address,tgp.mobile,tgp.test_num,tgp.department,tgp.dept,tgp.check_date,tgp.other_hazard_factors,tgp.work_type_text,ti.work_year,ti.exposure_work_year,ti.education,ti.marriage_date,ti.period,ti.cycle,ti.menarche,ti.last_menstruation,ti.existing_children,ti.abortion,ti.premature,ti.death,ti.abnormal_fetus,ti.allergies, ti.package_every_day,ti.smoke_year,ti.ml_every_day,ti.drink_year,ti.birthplace_name,ti.family_history,ti.past_medical_history,ti.disease_name FROM t_group_person as tgp,t_interrogation as ti WHERE tgp.person_name = ? AND ti.person_id = ?";
	SampleBarcodesViewMapper mapper;
	return sqlSession->executeQuery<ReportPreviewDO, SampleBarcodesViewMapper>(sql, mapper, "%s%s", person_name, person_id);
}

list<T_symptomDO> ReportPreviewDAO::queryT_symptom(const string& person_id,const string& code)
{
	string sql = "SELECT t_symptom.project_name, t_symptom.degree, t_symptom.course_time FROM t_symptom WHERE t_symptom.person_id = ?  AND t_symptom.`code` = ?";
	T_symptomMapper mapper;
	return sqlSession->executeQuery<T_symptomDO, T_symptomMapper>(sql, mapper, "%s%s", person_id, code);
}
