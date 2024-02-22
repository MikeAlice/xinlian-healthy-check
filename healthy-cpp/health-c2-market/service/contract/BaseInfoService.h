#pragma once
#ifndef _BASEINFO_SERVICE_
#define _BASEINFO_SERVICE_
#include <list>
#include "domain/vo/contract/BaseInfoVO.h"
#include "domain/query/contract/BaseInfoQuery.h"
#include "domain/dto/contract/BaseInfoDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class BaseInfoService
{
public:
	// 分页查询所有数据
	BaseInfoPageDTO::Wrapper listAll(const BaseInfoQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const BaseInfoDTO::Wrapper& dto);

};

#endif // !_SAMPLE_SERVICE_
