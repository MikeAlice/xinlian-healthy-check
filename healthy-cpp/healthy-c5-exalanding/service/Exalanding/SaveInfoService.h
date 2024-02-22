#pragma once
#ifndef _SAVE_INFO_SERVICE_
#define _SAVE_INFO_SERVICE_
#include <list>
#include "domain/vo/Exalanding/SaveInfoVO.h"
#include "domain/query/Exalanding/SaveInfoQuery.h"
#include "domain/dto/Exalanding/SaveInfoDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class SampleService
{
public:
	// 保存数据
	uint64_t saveData(const SaveInfoDTO::Wrapper& dto);
	
};

#endif // !_SAVE_INFO_SERVICE_