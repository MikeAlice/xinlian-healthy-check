#pragma once
#ifndef _NAMELIST_DO_
#define _NAMELIST_DO_
#include "../DoInclude.h"

/**
 * �����б����ݿ�ʵ����
 */
class NameListDO
{
	// ǩ��ʱ��
	CC_SYNTHESIZE(string, signingTime, SigningTime);
	// ί�е�λ
	CC_SYNTHESIZE(string, groupUnitName, GroupUnitName);
	// ���״̬
	CC_SYNTHESIZE(unsigned int, auditState, AuditState);
public:
	NameListDO() {
		signingTime = "";
		groupUnitName = "";
		auditState = 3;
	}
};

#endif // !_SAMPLE_DO_