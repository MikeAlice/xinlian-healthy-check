#pragma once
#ifndef _PERSON_DO_
#define _PERSON_DO_

#include "../DoInclude.h"

class PersonDO {

	//组合项目编号
	CC_SYNTHESIZE(string, id, Id);
	//组合项目名称
	CC_SYNTHESIZE(string, portfolioName, PortfolioName);
public:
	PersonDO() {
		id = "";
		portfolioName = "";
	}
};

#endif //!_PERSON_DO_
