#pragma once
#ifndef _UnitList_SERVICE_
#define _UnitList_SERVICE_
#include <list>
#include "domain/vo/getUserName/UnitVO.h"
#include "domain/query/getUserName/UnitQuery.h"
#include "domain/dto/getUserName/UnitListDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class UnitListService
{
public:
	// 分页查询所有数据
	UnitListPageDTO::Wrapper listAll(const UnitQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const UnitListDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const UnitListDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

