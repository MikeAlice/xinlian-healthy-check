#pragma once

#ifndef _PRINTMORE_SERVICE_
#define _PRINTMORE_SERVICE_
#include <list>
#include "domain/vo/printmore/PrintMoreVO.h"
#include "domain/dto/printmore/PrintMoreDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class PrintMoreService
{
public:
	// ��ȡ����λ��
	string downloadPrintMore(const uint64_t& id);
};

#endif // !_PRINTMORE_SERVICE_

