#pragma once
#ifndef _LIFEHISTORYCONTRONLLER_DO_
#define _LIFEHISTORYCONTRONLLER_DO_
#include "../DoInclude.h"

class LifeHistoryDO
{
	// 唯一编号
	CC_SYNTHESIZE(string, person_id, Person_id);
	// 现有子女（生育史）
	CC_SYNTHESIZE(int, existing_children, Existing_children);
	// 过敏史
	CC_SYNTHESIZE(string, allergies, Allergies);
	// 吸烟状态
	CC_SYNTHESIZE(string, smoke_state, Smoke_state);
	// 包每天
	CC_SYNTHESIZE(int, package_every_day, Package_every_day);
	// 吸烟年
	CC_SYNTHESIZE(int, smoke_year, Smoke_year);
	// 喝酒状态
	CC_SYNTHESIZE(string, drink_state, Drink_state);
	// ml每天
	CC_SYNTHESIZE(int, ml_every_day, Ml_every_day);
	// 喝酒年
	CC_SYNTHESIZE(int, drink_year, Drink_year);
	// 出生地
	CC_SYNTHESIZE(string, birthplace_name, Birthplace_name);
	// 家族史
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
