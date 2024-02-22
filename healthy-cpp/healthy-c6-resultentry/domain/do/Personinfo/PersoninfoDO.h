#pragma once
#ifndef _PERSONINFO_DO_
#define _PERSONINFO_DO_
#include "../DoInclude.h"

class PersoninfoDO
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
	PersoninfoDO() {
		name = "";
		sex = "";
		age = -1;
		physical_type = "";
		sporadic_physical = -1;
	}
};

#endif // !_PERSONINFO_DO_
