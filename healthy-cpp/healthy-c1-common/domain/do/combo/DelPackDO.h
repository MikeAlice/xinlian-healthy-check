#pragma once

#ifndef _DELPACKDO_H
#define _DELPACKDO_H
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class DelPackDO
{
	// ����
	CC_SYNTHESIZE(string, id, Id);

public:
	DelPackDO() {
		id = "";
	}
};
#endif // _DELPACKDO_H