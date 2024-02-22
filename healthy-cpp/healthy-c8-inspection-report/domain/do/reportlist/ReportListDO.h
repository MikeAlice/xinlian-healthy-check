#pragma once;

#ifndef _REPORT_LIST_DO_
#define _REPORT_LIST_DO_
#include "../DoInclude.h"

/**
 * 报告列表数据库实体类
 */
class ReportListDO
{
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
	// 体检日期
	CC_SYNTHESIZE(string, check_date, Check_date);
	// 是否合格
	CC_SYNTHESIZE(string, check_result, Check_result);
	// 体检单位
	CC_SYNTHESIZE(string, physical_unit, Physical_unit);
	// 审核状态
	CC_SYNTHESIZE(int, statu, Statu);
public:
	ReportListDO() {
		test_num = "";
		id_card = "";
		person_name = "";
		sex = "";
		age = 0;
		check_date = "";
		check_result = "";
		physical_unit = "";
		statu = 0;
	}
};
#endif