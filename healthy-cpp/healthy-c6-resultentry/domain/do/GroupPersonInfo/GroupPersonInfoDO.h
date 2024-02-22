#pragma once
#ifndef _GROUP_PERSON_INFO_DO_
#define _GROUP_PERSON_INFO_DO_
#include "../DoInclude.h"

class GroupPersonInfoDO
{

	//是否通过检查
	CC_SYNTHESIZE(int, is_pass, Is_pass);

	// 体检编号
	CC_SYNTHESIZE(string, test_num, Test_num);

	// 身份证号
	CC_SYNTHESIZE(string, id_card, Id_card);

	// 姓名
	CC_SYNTHESIZE(string, person_name, Person_name);

	// 性别
	CC_SYNTHESIZE(string, sex, Sex);

	// 年龄
	CC_SYNTHESIZE(int, age, Age);

	// 体检类型
	CC_SYNTHESIZE(string, physical_type, Physical_type);

	// 订单类型
	CC_SYNTHESIZE(int, sporadic_physical, Sporadic_physical);

	// 单位名称
	CC_SYNTHESIZE(string, dept, Dept);

	// 登记时间
	CC_SYNTHESIZE(string, create_time, Create_time);

public:
	GroupPersonInfoDO() {
		is_pass = 1;
		test_num = "";
		id_card = "";
		person_name = "";
		sex = "";
		age = -1;
		physical_type = "";
		sporadic_physical = 1;
		dept = "";
		create_time = "";
	}
};

#endif // !_GROUP_PERSON_INFO_DO_
