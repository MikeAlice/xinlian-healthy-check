#pragma once

#ifndef _STATISTICALMESSAGEQUERY_DO_
#define _STATISTICALMESSAGEQUERY_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class StatisticalMessageDO
{
	// Ψһ���
	CC_SYNTHESIZE(string, id, Id);
	//���״̬
	CC_SYNTHESIZE(int, isPass, IsPass);
public:
	StatisticalMessageDO() {
		id = "";
		isPass = 1;
	}
};

#endif // !_SAMPLE_DO_
