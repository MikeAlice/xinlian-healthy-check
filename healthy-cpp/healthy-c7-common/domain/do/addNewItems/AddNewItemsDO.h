#pragma once
#ifndef _ADDNEWITEMS_DO_
#define _ADDNEWITEMS_DO_
#include "../DoInclude.h"

/**
 * 新增复查记录数据库实体类
 */
class AddNewItemsDO
{
	CC_SYNTHESIZE(string, id, Id);
	//复查项目id
	CC_SYNTHESIZE(string, checkProjectId, CheckProjectId);
	//复查项目名称
	CC_SYNTHESIZE(string, checkProjectName, CheckProjectName);
	//组合项目id
	CC_SYNTHESIZE(string, portfolioProjectId, PortfolioProjectId);
	//组合项目名称
	CC_SYNTHESIZE(string, portfolioProjectName, PortfolioProjectName);
	//复查原因
	CC_SYNTHESIZE(string, reason, Reason);

public:
	AddNewItemsDO() {
		checkProjectId = "";
		checkProjectName = "";
		portfolioProjectId = "";
		portfolioProjectName = "";
		reason = "";
	}
};

#endif // !_ADDNEWITEMS_DO_