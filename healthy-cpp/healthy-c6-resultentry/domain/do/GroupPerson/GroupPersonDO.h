#pragma once
#ifndef _GroupPerson_DO_
#define _GroupPerson_DO_
#include "../DoInclude.h"

class GroupPersonDO
{
	// ����
	CC_SYNTHESIZE(string, name, Name);
	// �Ա�
	CC_SYNTHESIZE(string, sex, Sex);
	// ����
	CC_SYNTHESIZE(int, age, Age);
	// �������
	CC_SYNTHESIZE(string, physical_type, Physical_type);
	// �Ƿ��������
	CC_SYNTHESIZE(int, sporadic_physical, Sporadic_physical);


public:
	GroupPersonDO() {
		name = "";
		sex = "";
		age = -1;
		physical_type = "";
		sporadic_physical = -1;
	}
};

#endif // !_GroupPerson_DO_
