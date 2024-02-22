#pragma once
#ifndef _UNIT_PEOPLE_DO_
#define _UNIT_PEOPLE_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class UnitPeopleDO
{
	//do与dto一一对应，互相转化
	//姓名、性别、证件号码、生日、年龄、是否婚配、手机号码
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
