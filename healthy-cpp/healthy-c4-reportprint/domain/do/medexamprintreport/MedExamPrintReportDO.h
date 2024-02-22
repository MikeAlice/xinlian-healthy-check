#pragma once
#ifndef _MEDEXAMPRINTREPORT_DO_
#define _MEDEXAMPRINTREPORT_DO_
#include "../DoInclude.h"

/**
 * 检测人员数据库实体类
 * 负责人：小智
 */
class MedExamPrintReportDO
{
	// 编号
	CC_SYNTHESIZE(uint64_t, id, Id);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(uint32_t, age, Age);
	// 审核
	CC_SYNTHESIZE(bool, statu, Statu);
	// 打印
	CC_SYNTHESIZE(bool, printState, PrintState);
	// 零星检查
	CC_SYNTHESIZE(bool, sporadicPhysical, SporadicPhysical);

public:
	MedExamPrintReportDO() {
		id = 0;
		name = "";
		sex = "";
		age = -1;
		statu = false;
		printState = false;
		sporadicPhysical = false;
	}
};

#endif // !_MEDEXAMPRINTREPORT_DO_
