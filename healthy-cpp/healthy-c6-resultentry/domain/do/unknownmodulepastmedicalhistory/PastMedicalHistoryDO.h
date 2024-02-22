#pragma once
#ifndef _PASTMEDICALHISTORYCONTRONLLER_DO_
#define _PASTMEDICALHISTORYCONTRONLLER_DO_
#include "../DoInclude.h"

class PastMedicalHistoryDO
{
	// Ψһ���
	CC_SYNTHESIZE(string, person_id, Person_id);
	// ����
	CC_SYNTHESIZE(int, abortion, Abortion);
	// ���
	CC_SYNTHESIZE(int, premature, Premature);
	// ����
	CC_SYNTHESIZE(int, death, Death);
	// �쳣̥
	CC_SYNTHESIZE(int, abnormal_fetus, Abnormal_fetus);
	// �¾�ʷ
	CC_SYNTHESIZE(string, menstrual_history, Menstrual_history);
	// �¾��쳣��Ϣ
	CC_SYNTHESIZE(string, menstrual_info, Menstrual_info);
	// ����ʷ
	CC_SYNTHESIZE(string, allergies, Allergies);
	// �����쳣��Ϣ
	CC_SYNTHESIZE(string, allergies_info, Allergies_info);
	// ������ʷ
	CC_SYNTHESIZE(string, past_medical_history, Past_medical_history);
	// ������ʷ������Ϣ
	CC_SYNTHESIZE(string, past_medical_history_other_info, Past_medical_history_other_info);

public:
	PastMedicalHistoryDO() {
		person_id = "";
		abortion = -1;
		premature = -1;
		death = -1;
		abnormal_fetus = -1;
		menstrual_history = "";
		menstrual_info = "";
		allergies = "";
		allergies_info = "";
		past_medical_history = "";
		past_medical_history_other_info = "";
	}
};

#endif // !_GroupPerson_DO_
