#ifndef _RESULTLISTDO_H_
#define _RESULTLISTDO_H_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class resultListDO
{
	// ���
	CC_SYNTHESIZE(string, id, Id);
	// ����
	CC_SYNTHESIZE(string, condition, Conditon);
	// �ʺ��Ա�
	CC_SYNTHESIZE(string, genderAppropriate, GenderAppropriate);
	// ����id
	CC_SYNTHESIZE(string, positiveId, PositiveId);
	// ����
	CC_SYNTHESIZE(string, projectName, ProjectName);
	// �ж�����
	CC_SYNTHESIZE(string, judgmentCondition, JudgmentCondition);
	// �ų����Խ��
	CC_SYNTHESIZE(string, excludePositive, ExcludePositive);
	// ����
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