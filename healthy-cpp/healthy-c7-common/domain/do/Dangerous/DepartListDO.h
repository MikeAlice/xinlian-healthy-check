#pragma once

#ifndef _DEPART_LIST_DO_
#define _DEPART_LIST_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class DepartListDO
{
	//��������
	CC_SYNTHESIZE(string, officeName, OfficeName);
	//��Ŀ����
	CC_SYNTHESIZE(string, projectName, ProjectName);
	//���
	CC_SYNTHESIZE(string, result, Result);
	//�ο���Χ
	CC_SYNTHESIZE(string, scope, Scope);
	//��Աid
	CC_SYNTHESIZE(string, personid, Personid);
	

public:
	DepartListDO() {
		officeName = "��";
		projectName = "��";
		result = "";
		scope = "";
		personid = "";
	}
};

#endif // !_SAMPLE_DO_