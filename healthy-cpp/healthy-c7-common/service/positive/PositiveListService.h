#pragma once
#ifndef _POSITIVE_LIST_SERVICE_
#define _POSITIVE_LIST_SERVICE_
#include <list>
#include "domain/vo/positive/positiveVO.h"
#include "domain/query/positive/positiveQuery.h"
#include "domain/dto/positive/positiveListDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class PositiveListService
{
public:
	// 分页查询所有数据
	PositiveListPageDTO::Wrapper listAll(const PositiveQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const PositiveListDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const PositiveListDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_
