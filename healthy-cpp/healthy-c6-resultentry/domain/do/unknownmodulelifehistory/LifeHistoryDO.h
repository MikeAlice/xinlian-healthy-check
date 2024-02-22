#pragma once
#ifndef _LIFEHISTORYCONTRONLLER_DO_
#define _LIFEHISTORYCONTRONLLER_DO_
#include "../DoInclude.h"

class LifeHistoryDO
{
	// Ψһ���
	CC_SYNTHESIZE(string, person_id, Person_id);
	// ������Ů������ʷ��
	CC_SYNTHESIZE(int, existing_children, Existing_children);
	// ����ʷ
	CC_SYNTHESIZE(string, allergies, Allergies);
	// ����״̬
	CC_SYNTHESIZE(string, smoke_state, Smoke_state);
	// ��ÿ��
	CC_SYNTHESIZE(int, package_every_day, Package_every_day);
	// ������
	CC_SYNTHESIZE(int, smoke_year, Smoke_year);
	// �Ⱦ�״̬
	CC_SYNTHESIZE(string, drink_state, Drink_state);
	// mlÿ��
	CC_SYNTHESIZE(int, ml_every_day, Ml_every_day);
	// �Ⱦ���
	CC_SYNTHESIZE(int, drink_year, Drink_year);
	// ������
	CC_SYNTHESIZE(string, birthplace_name, Birthplace_name);
	// ����ʷ
	CC_SYNTHESIZE(string, family_history, Family_history);

public:
	LifeHistoryDO() {
		person_id = "";
		existing_children = -1;
		allergies = "";
		smoke_state = "";
		package_every_day = -1;
		smoke_year = -1;
		drink_state = "";
		ml_every_day = -1;
		drink_year = -1;
		birthplace_name = "";
		family_history = "";
	}
};

#endif // !_GroupPerson_DO_
