#pragma once
#ifndef _GroupPerson_DO_
#define _GroupPerson_DO_
#include "../DoInclude.h"

class GroupPersonDO
{
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	// 体检类型
	CC_SYNTHESIZE(string, physical_type, Physical_type);
	// 是否零星体检
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
