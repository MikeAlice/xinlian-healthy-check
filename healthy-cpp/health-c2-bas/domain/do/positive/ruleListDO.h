#ifndef _RULELIST_DO_
#define _RULELIST_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class ruleListDO
{
	// Ψһ���
	CC_SYNTHESIZE(string, id, Id);
	// ��Ŀ����
	CC_SYNTHESIZE(string, projectName, ProjectName);
	//����
	CC_SYNTHESIZE(string, type, Type);
	// ����ֵ
	CC_SYNTHESIZE(string, regularValue, RegularValue);
	//���Թ���Id 
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