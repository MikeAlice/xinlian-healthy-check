#ifndef _REPORTPREVIEW_DO_
#define _REPORTPREVIEW_DO_
#include "../DoInclude.h"

/*
* ����Ԥ�����ݿ�ʵ����
*/
class ReportPreviewDO
{
	//��Ա����
	CC_SYNTHESIZE(string, person_name, Person_name);
	//t_group_person
	//�Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	//֤������
	CC_SYNTHESIZE(string, id_card, Id_card);
	//��������
	CC_SYNTHESIZE(string, birth, Birth);
	//����
	CC_SYNTHESIZE(int, age, Age);
	//��ͥסַ
	CC_SYNTHESIZE(string, home_address, Home_address);
	//�ֻ�����
	CC_SYNTHESIZE(string, mobile, Mobile);
	//�����
	CC_SYNTHESIZE(string, test_num, Test_num);
	// ��������
	CC_SYNTHESIZE(string, department, Department);
	//�����Ա��������(��λ����)
	CC_SYNTHESIZE(string, dept, Dept);
	//�������
	CC_SYNTHESIZE(string, check_date, Check_date);
	//Σ����������
	CC_SYNTHESIZE(string, other_hazard_factors, Other_hazard_factors);
	//��������
	CC_SYNTHESIZE(string, work_type_text, Work_type_text);
	//t_interrogation
	// �ܹ�������
	CC_SYNTHESIZE(int, work_year, Work_year);
	// �Ӻ���������
	CC_SYNTHESIZE(int, exposure_work_year, Exposure_work_year);
	// �Ļ��̶�
	CC_SYNTHESIZE(string, education, Education);
	// ����ʷ-�������
	CC_SYNTHESIZE(string, marriage_date, Marriage_date);
	// �¾�״̬�����ڣ����ڣ�
	CC_SYNTHESIZE(int, period, Period);
	CC_SYNTHESIZE(int, cycle, Cycle);
	// ����
	CC_SYNTHESIZE(int, menarche, Menarche);
	//ĩ���¾�/ͣ������
	CC_SYNTHESIZE(string, last_menstruation, Last_menstruation);
	// ������Ů
	CC_SYNTHESIZE(string, existing_children, Existing_children);
	// ����
	CC_SYNTHESIZE(string, abortion, Abortion);
	// ���
	CC_SYNTHESIZE(string, premature, Premature);
	// ����
	CC_SYNTHESIZE(string, death, Death);
	// �쳣̥
	CC_SYNTHESIZE(string, abnormal_fetus, Abnormal_fetus);
	// ����ʷ
	CC_SYNTHESIZE(string, allergies, Allergies);
	// ��ÿ��
	CC_SYNTHESIZE(int, package_every_day, Package_every_day);
	// ������
	CC_SYNTHESIZE(int, smoke_year, Smoke_year);
	// mlÿ��
	CC_SYNTHESIZE(int, ml_every_day, Ml_every_day);
	// �Ⱦ���
	CC_SYNTHESIZE(int, drink_year, Drink_year);
	// ����������
	CC_SYNTHESIZE(string, birthplace_name, Birthplace_name);
	// ����ʷ
	CC_SYNTHESIZE(string, family_history, Family_history);
	// ������ʷ������Ϣ
	CC_SYNTHESIZE(string, past_medical_history, Past_medical_history);
	// ����
	CC_SYNTHESIZE(string, disease_name, Disease_name);

public:
	ReportPreviewDO() {

	}
};
/*
* ����֢״ѯ�����ݿ�ʵ����
*/
class T_symptomDO {

	//t_symptom
	// �̶�
	CC_SYNTHESIZE(string, degree, Degree);
	// ʱ��
	CC_SYNTHESIZE(string, course_time, Course_time);
	//��Ŀ����
	CC_SYNTHESIZE(string, project_name, Project_name);
public:
	T_symptomDO() {

	}
};

#endif // !_REPORTPREVIEW_DO_
