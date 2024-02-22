#ifndef _RESULTLISTDO_H_
#define _RESULTLISTDO_H_
#include "../DoInclude.h"

/**
 * 数据库实体类
 */
class resultListDO
{
	// 编号
	CC_SYNTHESIZE(string, id, Id);
	// 条件
	CC_SYNTHESIZE(string, condition, Conditon);
	// 适合性别
	CC_SYNTHESIZE(string, genderAppropriate, GenderAppropriate);
	// 阳性id
	CC_SYNTHESIZE(string, positiveId, PositiveId);
	// 规则
	CC_SYNTHESIZE(string, projectName, ProjectName);
	// 判断条件
	CC_SYNTHESIZE(string, judgmentCondition, JudgmentCondition);
	// 排除阳性结果
	CC_SYNTHESIZE(string, excludePositive, ExcludePositive);
	// 类型
	CC_SYNTHESIZE(string, type, Type);
public:
	resRuleListDO() {
		id = "0";
		condition = "";
		genderAppropriate = "";
		positiveId = "";
		projectName = "";
		judgmentCondition = "";
		excludePositive = "";
		type = "";
};

#endif // !_RESULTLISTDO_H_