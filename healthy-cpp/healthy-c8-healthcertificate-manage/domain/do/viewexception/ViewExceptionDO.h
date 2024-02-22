#pragma once

#ifndef _VIEW_EXCEPTION_DO_
#define _VIEW_EXCEPTION_DO_
#include "../DoInclude.h"

/**
 * 报告列表数据库实体类
 */
class ViewExceptionDO
{
	// 健康证编码
	CC_SYNTHESIZE(string, exception_message, Exception_message);

public:
	ViewExceptionDO() {
		exception_message = "";
	}
};
#endif