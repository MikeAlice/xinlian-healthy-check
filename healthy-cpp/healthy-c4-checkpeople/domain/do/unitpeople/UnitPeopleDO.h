#pragma once
#ifndef _UNIT_PEOPLE_DO_
#define _UNIT_PEOPLE_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class UnitPeopleDO
{
	//do��dtoһһ��Ӧ������ת��
	//�������Ա�֤�����롢���ա����䡢�Ƿ���䡢�ֻ�����
	CC_SYNTHESIZE(string, person_name, PersonName);
	CC_SYNTHESIZE(string, sex, Sex);
	CC_SYNTHESIZE(string, id_card, IdCard); 
	CC_SYNTHESIZE(string, birth, Birth);
	CC_SYNTHESIZE(int, age, Age);
	CC_SYNTHESIZE(string, is_marry, IsMarry);
	CC_SYNTHESIZE(string, mobile, Mobile);
public:
	UnitPeopleDO() {
		person_name = "";
		sex = "";
		id_card = "";
		birth = "";
		age = 0;
		is_marry = "";
		mobile = "";
	}
};

#endif // !_UNIT_PEOPLE_DO_
