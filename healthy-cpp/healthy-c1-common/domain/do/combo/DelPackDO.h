#pragma once

#ifndef _DELPACKDO_H
#define _DELPACKDO_H
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class DelPackDO
{
	// 主键
	CC_SYNTHESIZE(string, id, Id);

public:
	DelPackDO() {
		id = "";
	}
};
#endif // _DELPACKDO_H