#pragma once
#ifndef _UP_FILE_DO_
#define _UP_FILE_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class UpFileDO
{
	// ��Աid
	CC_SYNTHESIZE(string, person_id, Person_id);
	
public:
	UpFileDO() {
		person_id = "";
	}
};

#endif // !_UP_FILE_DO_
