#pragma once
#ifndef _Term_List_DO_
#define _Term_List_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class TermListDO
{
	// ����
	CC_SYNTHESIZE(string, id, Id);
	// ID
	CC_SYNTHESIZE(string, officeId, OfficeId);
	// Σ������
	CC_SYNTHESIZE(string, hazardFactorsText, HazardFactorsText);
	// ����
	CC_SYNTHESIZE(string, inspectType, InspectType);
	//����
	CC_SYNTHESIZE(string, content, Content);
	//�ڸ�״̬
	CC_SYNTHESIZE(string, workStateText, WorkStateText);
public:
	TermListDO() {
		id = "";
		officeId = "";
		hazardFactorsText = "";
		inspectType = "";
		content = "";
		workStateText = "";
	}
};

#endif // !_Term_List_DO_