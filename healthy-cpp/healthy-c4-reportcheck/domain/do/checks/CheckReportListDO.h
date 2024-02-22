#pragma once
#ifndef _CHECKREPORTLIST_DO_
#define _CHECKREPORTLIST_DO_
#include "../DoInclude.h"

/**
 * 获取列表数据库实体类
 * 负责人Z
 */
class CheckReportListDO
{
	// 编号
protected: string id; public: string getId(void) const {
	return id;
}public: void setId(string var) {
	id = var;
};
	// 姓名
	CC_SYNTHESIZE(string, person_name, Person_name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	//是否过审
	CC_SYNTHESIZE(bool, statu, Statu);
	// 是否打印
	CC_SYNTHESIZE(bool, print_state, Print_state);
	// 是否零星体检
	CC_SYNTHESIZE(bool, sporadic_physical, Sporadic_physical);
public:
	CheckReportListDO() {
		id = "";
		person_name = "";
		sex = "";
		age = 0;
		statu = false;
		print_state = false;
		sporadic_physical = false;
	}
};

#endif // !_CHECKREPORTLIST_DO_
