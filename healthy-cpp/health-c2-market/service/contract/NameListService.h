#pragma once
#ifndef _NAMELIST_SERVICE_
#define _NAMELIST_SERVICE_
#include <list>
#include "domain/vo/contract/NameListVO.h"
#include "domain/query/contract/NameListQuery.h"
#include "domain/dto/contract/NameListDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class NameListService
{
public:
	// 分页查询所有数据
	NameListPageDTO::Wrapper listAll(const NameListQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const NameListDTO::Wrapper& dto);

};

#endif // !_SAMPLE_SERVICE_
