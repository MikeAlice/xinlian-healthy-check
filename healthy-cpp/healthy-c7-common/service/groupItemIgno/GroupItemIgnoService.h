#pragma once

#ifndef _GROUPITEMIGNO_SERVICE_
#define _GROUPITEMIGNO_SERVICE_

#include "domain/dto/groupItemIgno/GroupItemIgnoDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class GroupItemIgnoService
{
public:

	// 修改数据ignore_state = 2
	bool updateData(const GroupItemIgnoDTO::Wrapper& dto);
	
};

#endif // !_SAMPLE_SERVICE_

