#pragma once
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "domain/vo/add/AddVo.h"
#include "domain/query/add/AddUnit.h"
#include "domain/dto/add/AddUnitDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class addService
{
public:

	// 保存数据
	uint64_t saveData(const AddUnitDTO::Wrapper& dto);

};

#endif // !_SAMPLE_SERVICE_