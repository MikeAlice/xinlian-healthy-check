#ifndef _REPORTREVIEW_DO_
#define _REPORTREVIEW_DO_
#include "../DoInclude.h"

/**
 * ����������ݿ�ʵ����
 */
class ReportReviewDO
{
	//�����
	CC_SYNTHESIZE(string, testNum, TestNum);
public:
	ReportReviewDO() {
		testNum = "";
	}
};

#endif