#pragma once

#ifndef _COUNTCHECK_DO_
#define _COUNTCHECK_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class CountCheckDO
{
	//API_DTO_FIELD_DEFAULT(UInt32, audit_level_already, ZH_WORDS_GETTER("countcheck.field.audit_level"));

	// ����
	CC_SYNTHESIZE(UInt32, audit_level, Audit_level);

public:
	CountCheckDO() {
		audit_level = 4;
	}
};

#endif // !_COUNTCHECK_DO_

