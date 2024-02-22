#ifndef _REPORTREVIEW_DO_
#define _REPORTREVIEW_DO_
#include "../DoInclude.h"

/**
 * 报告审核数据库实体类
 */
class ReportReviewDO
{
	//体检编号
	CC_SYNTHESIZE(string, testNum, TestNum);
public:
	ReportReviewDO() {
		testNum = "";
	}
};

#endif