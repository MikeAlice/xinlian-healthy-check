#pragma once
#ifndef _PROFESSIONALHISTORYCONTRONLLER_DO_
#define _PROFESSIONALHISTORYCONTRONLLER_DO_
#include "../DoInclude.h"

class ProfessionalHistoryDO
{
	// Ψһ���
	CC_SYNTHESIZE(string, person_id, Person_id);
	// ��ʼʱ��
	CC_SYNTHESIZE(string, start_date, Start_date);
	// ����ʱ��
	CC_SYNTHESIZE(string, end_date, End_date);
	// ������λ
	CC_SYNTHESIZE(string, work_unit, Work_unit);
	// ���䣨���ţ�
	CC_SYNTHESIZE(string, department, Department);
	// ����
	CC_SYNTHESIZE(string, work_type_text, Work_type_text);
	// Σ������
	CC_SYNTHESIZE(string, hazard_factors_text, Hazard_factors_text);
	// ������ʩ
	CC_SYNTHESIZE(string, protective_measures, Protective_measures);
	// �Ӵ�ʱ��
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
