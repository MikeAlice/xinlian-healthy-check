#pragma once
#ifndef _PASTMEDICALHISTORYCONTRONLLER_DO_
#define _PASTMEDICALHISTORYCONTRONLLER_DO_
#include "../DoInclude.h"

class PastMedicalHistoryDO
{
	// 唯一编号
	CC_SYNTHESIZE(string, person_id, Person_id);
	// 流产
	CC_SYNTHESIZE(int, abortion, Abortion);
	// 早产
	CC_SYNTHESIZE(int, premature, Premature);
	// 死亡
	CC_SYNTHESIZE(int, death, Death);
	// 异常胎
	CC_SYNTHESIZE(int, abnormal_fetus, Abnormal_fetus);
	// 月经史
	CC_SYNTHESIZE(string, menstrual_history, Menstrual_history);
	// 月经异常信息
	CC_SYNTHESIZE(string, menstrual_info, Menstrual_info);
	// 过敏史
	CC_SYNTHESIZE(string, allergies, Allergies);
	// 过敏异常信息
	CC_SYNTHESIZE(string, allergies_info, Allergies_info);
	// 既往病史
	CC_SYNTHESIZE(string, past_medical_history, Past_medical_history);
	// 既往病史其他信息
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
