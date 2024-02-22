#pragma once

#ifndef _PRINTMORE_SERVICE_
#define _PRINTMORE_SERVICE_
#include <list>
#include "domain/vo/printmore/PrintMoreVO.h"
#include "domain/dto/printmore/PrintMoreDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class PrintMoreService
{
public:
	// 获取保存位置
	string downloadPrintMore(const uint64_t& id);
};

#endif // !_PRINTMORE_SERVICE_

