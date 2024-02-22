#pragma once
#ifndef _UP_FILE_DO_
#define _UP_FILE_DO_
#include "../DoInclude.h"

/**
 * 数据库实体类
 */
class UpFileDO
{
	// 人员id
	CC_SYNTHESIZE(string, person_id, Person_id);
	
public:
	UpFileDO() {
		person_id = "";
	}
};

#endif // !_UP_FILE_DO_
