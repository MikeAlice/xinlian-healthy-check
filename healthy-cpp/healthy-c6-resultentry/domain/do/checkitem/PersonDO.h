#pragma once
#ifndef _PERSON_DO_
#define _PERSON_DO_

#include "../DoInclude.h"

class PersonDO {

	//�����Ŀ���
	CC_SYNTHESIZE(string, id, Id);
	//�����Ŀ����
	CC_SYNTHESIZE(string, portfolioName, PortfolioName);
public:
	PersonDO() {
		id = "";
		portfolioName = "";
	}
};

#endif //!_PERSON_DO_
