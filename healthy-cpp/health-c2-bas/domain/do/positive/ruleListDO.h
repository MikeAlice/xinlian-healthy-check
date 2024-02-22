#ifndef _RULELIST_DO_
#define _RULELIST_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类
 */
class ruleListDO
{
	// 唯一编号
	CC_SYNTHESIZE(string, id, Id);
	// 项目名称
	CC_SYNTHESIZE(string, projectName, ProjectName);
	//类型
	CC_SYNTHESIZE(string, type, Type);
	// 规则值
	CC_SYNTHESIZE(string, regularValue, RegularValue);
	//阳性规则Id 
	CC_SYNTHESIZE(string, positiveResultId, PositiveResultId);
public:
	ruleListDO() {
		id = "0";
		projectName = "";
		type = "";
		regularValue = "";
		positiveResultId = "";
	}
};

#endif // !_RULELIST_DO_