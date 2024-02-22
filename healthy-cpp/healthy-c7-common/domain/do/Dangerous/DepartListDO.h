#pragma once

#ifndef _DEPART_LIST_DO_
#define _DEPART_LIST_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class DepartListDO
{
	//科室名称
	CC_SYNTHESIZE(string, officeName, OfficeName);
	//项目名称
	CC_SYNTHESIZE(string, projectName, ProjectName);
	//结果
	CC_SYNTHESIZE(string, result, Result);
	//参考范围
	CC_SYNTHESIZE(string, scope, Scope);
	//人员id
	CC_SYNTHESIZE(string, personid, Personid);
	

public:
	DepartListDO() {
		officeName = "无";
		projectName = "无";
		result = "";
		scope = "";
		personid = "";
	}
};

#endif // !_SAMPLE_DO_