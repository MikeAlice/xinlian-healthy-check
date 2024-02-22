#pragma once
#ifndef _ADD_DO_
#define _ADD_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class addDO
{

	//查询类型
	CC_SYNTHESIZE(string, type, Type);
	// 编号
	CC_SYNTHESIZE(int, idCard, IdCard);
	// 体检姓名
	CC_SYNTHESIZE(string, u_name, U_Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);

	CC_SYNTHESIZE(int, linkPhone, LinkPhone);
	CC_SYNTHESIZE(string, name, Name);
	CC_SYNTHESIZE(string, marriage, Marriage);
	CC_SYNTHESIZE(string, g_name, G_name);
	CC_SYNTHESIZE(int, is_pass, Is_pass);

public:
	addDO() {
		type = "";
		u_name = "";
		sex = "";
		age = -1;
		linkPhone = 1;
		name = "";
		marriage = "";
		g_name = "";
		is_pass = 0;
		idCard = 0;
	}
};

#endif // !_SAMPLE_DO_