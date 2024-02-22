#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���ܵ���
 @Date: 2024/1/19 17:36:29

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _RESULTSLIST_DO_
#define _RESULTSLIST_DO_
#include "../DoInclude.h"

/**
 * ���������ݿ�ʵ����
 */
class ResultsListDO
{
	// �����
	CC_SYNTHESIZE(string, test_num, CheckId);
	// ����
	CC_SYNTHESIZE(string, person_name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	// ID
	CC_SYNTHESIZE(string, id, Id);
	//���֤��
	CC_SYNTHESIZE(string, id_card, IdCard);
	//���״̬
	//CC_SYNTHESIZE(string, check_status, CheckState);
	CC_SYNTHESIZE(string, statu, CheckState);
	//�ڸ�״̬
	CC_SYNTHESIZE(string, work_state_text, DutyState);
	//Σ������
	CC_SYNTHESIZE(string, hazard_factors_text, DangerFactors);
	//�������
	CC_SYNTHESIZE(string, check_date, CheckDate);
	//������
	CC_SYNTHESIZE(string, comments, CheckResults);

	////δ�����Ŀ
	//CC_SYNTHESIZE(string, comments, checkResults);
	//DTO_FIELD(String, unfinishedProject);
	//DTO_FIELD_INFO(unfinishedProject) {
	//	info->description = ZH_WORDS_GETTER("results.field.unfinishedProject");
	//}
	
	//��λ����
	CC_SYNTHESIZE(string, unit_name, unitName);
	//���״̬/
	CC_SYNTHESIZE(int32_t, audit_state, State);
	

public:
	ResultsListDO() {
		test_num = "";
		person_name = "";
		sex = "";
		age = -1;
		id_card = "";
		statu = "";
		work_state_text = "";
		hazard_factors_text = "";
		check_date = "";
		comments = "";
		unit_name = "";
		audit_state = 0;
	}
};

#endif // !_RESULTSLIST_DO_
