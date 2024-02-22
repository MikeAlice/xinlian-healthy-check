#pragma once

#ifndef _STATISTICALMESSAGEQUERY_DO_
#define _STATISTICALMESSAGEQUERY_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class StatisticalMessageDO
{
	// 唯一编号
	CC_SYNTHESIZE(string, id, Id);
	//体检状态
	CC_SYNTHESIZE(int, isPass, IsPass);
public:
	StatisticalMessageDO() {
		id = "";
		isPass = 1;
	}
};

#endif // !_SAMPLE_DO_
