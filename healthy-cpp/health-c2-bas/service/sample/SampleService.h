#pragma once
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
#include "../../domain/dto/sample/SampleDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class SampleService
{
public:
	// 修改数据
	bool updateData(const SampleDTO::Wrapper& dto);

};

#endif // !_SAMPLE_SERVICE_

