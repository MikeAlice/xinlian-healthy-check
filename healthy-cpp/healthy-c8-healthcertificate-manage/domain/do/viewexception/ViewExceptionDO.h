#pragma once

#ifndef _VIEW_EXCEPTION_DO_
#define _VIEW_EXCEPTION_DO_
#include "../DoInclude.h"

/**
 * �����б����ݿ�ʵ����
 */
class ViewExceptionDO
{
	// ����֤����
	CC_SYNTHESIZE(string, exception_message, Exception_message);

public:
	ViewExceptionDO() {
		exception_message = "";
	}
};
#endif