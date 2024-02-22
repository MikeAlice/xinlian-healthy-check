#pragma once
#ifndef _DEPART_LIST_SERVICE_
#define _DEPART_LIST_SERVICE_
#include <list>
#include "domain/vo/Dangerous/DepartVO.h"
#include "domain/query/Dangerous/DepartQuery.h"
#include "domain/dto/Dangerous/DepartListDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class DepartListService
{
public:
	// 分页查询所有数据
	DepartListPageDTO::Wrapper listAll(const DepartQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_