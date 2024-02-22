#pragma once

#ifndef _PREVIEWENTRUSTDO_H_
#define _PREVIEWENTRUSTDO_H_

#include "../DoInclude.h"

class PreviewEntrustInfoDO
{
	// orderCode\groupUnitName\linkMan2\linkPhone2\startDate\endDate
	CC_SYNTHESIZE(string, orderCode, OrderCode);
	CC_SYNTHESIZE(string, groupUnitName, GroupUnitName);
	CC_SYNTHESIZE(string, linkMan2, LinkMan2);
	CC_SYNTHESIZE(string, linkPhone2, LinkPhone2);
	CC_SYNTHESIZE(string, startDate, StartDate);
	CC_SYNTHESIZE(string, endDate, EndDate);
public:
	PreviewEntrustInfoDO():orderCode(""), groupUnitName(""), linkMan2(""), linkPhone2(""), startDate(""), endDate("")
	{}
};

class PreviewEntrustUrlDO
{
	CC_SYNTHESIZE(string, orderPath, OrderPath);
	CC_SYNTHESIZE(string, orderLicensePath, OrderLicensePath);
	CC_SYNTHESIZE(string, orderEvaluatePath, OrderEvaluatePath);
	CC_SYNTHESIZE(string, orderInfoPath, OrderInfoPath);
	CC_SYNTHESIZE(string, orderPersonDataPath, OrderPersonDataPath);
public:
	PreviewEntrustUrlDO():orderPath(""), orderLicensePath(""), orderEvaluatePath(""), orderInfoPath(""), orderPersonDataPath("")
	{}
};
#endif // !_PREVIEWENTRUSTDO_H_
