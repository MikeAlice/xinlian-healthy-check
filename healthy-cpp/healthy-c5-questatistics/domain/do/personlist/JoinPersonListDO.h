#pragma once

#ifndef _JOINPERSONLIST_DO_
#define _JOINPERSONLIST_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class JoinPersonListDO
{
	// 唯一编号
	CC_SYNTHESIZE(string, id, Id);
	//体检编号
	CC_SYNTHESIZE(string, testNum, TestNum);
	// 姓名
	CC_SYNTHESIZE(string, name, Name);
	// 性别
	CC_SYNTHESIZE(string, sex, Sex);
	// 年龄
	CC_SYNTHESIZE(int, age, Age);
	//身份证号
	CC_SYNTHESIZE(int, idCard, IdCard);
	//体检状态
	CC_SYNTHESIZE(string, checkStatus, CheckStatus);
	//在岗状态
	CC_SYNTHESIZE(string, workStateText, WorkStateText);
	//危害因素
	CC_SYNTHESIZE(string, hazardFactor, HazardFactor);
	//体检日期
	CC_SYNTHESIZE(int, checkDate, CheckDate);
	//体检结论
	CC_SYNTHESIZE(string, comments, Comments);
	//未完成项目
	CC_SYNTHESIZE(string, unfinishedTerm, UnfinishedTerm);
public:
	JoinPersonListDO() {
		id = "";
		testNum = "";
		name = "";
		sex = "";
		age = -1;
		idCard = 2;
		checkStatus = "";
		workStateText = "";
		hazardFactor = "";
		checkDate = 3;
		comments = "";
		unfinishedTerm = "";
	}
};

#endif // !_SAMPLE_DO_
