#pragma once
#ifndef _ADDNEWITEMS_DO_
#define _ADDNEWITEMS_DO_
#include "../DoInclude.h"

/**
 * ���������¼���ݿ�ʵ����
 */
class AddNewItemsDO
{
	CC_SYNTHESIZE(string, id, Id);
	//������Ŀid
	CC_SYNTHESIZE(string, checkProjectId, CheckProjectId);
	//������Ŀ����
	CC_SYNTHESIZE(string, checkProjectName, CheckProjectName);
	//�����Ŀid
	CC_SYNTHESIZE(string, portfolioProjectId, PortfolioProjectId);
	//�����Ŀ����
	CC_SYNTHESIZE(string, portfolioProjectName, PortfolioProjectName);
	//����ԭ��
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