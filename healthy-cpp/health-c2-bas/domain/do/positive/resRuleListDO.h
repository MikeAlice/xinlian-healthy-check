#ifndef _RESRULELIST_DO_
#define _RESRULELIST_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class resRuleListDO 
{
	// Ψһ���
	CC_SYNTHESIZE(string, id, Id);
	// ����
	CC_SYNTHESIZE(string, condition, Condition);
	// �ʺ��Ա�
	CC_SYNTHESIZE(string, genderAppropriate, GenderAppropriate);
	// ����Id
	CC_SYNTHESIZE(string, positiveId, PositiveId);
	// ����
	CC_SYNTHESIZE(string, projectName, ProjectName);
	// �ж�����
	CC_SYNTHESIZE(string, judgmentCondition, JudgmentCondition);
	//�ų����Խ��
	CC_SYNTHESIZE(string, excludePositive, ExcludePositive);
	//����
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
	}
};

#endif // !_RESRULELIST_DO_