#pragma once
#ifndef _UNIT_PEOPLE_SERVICE_
#define _UNIT_PEOPLE_SERVICE_
#include <list>
#include "domain/vo/unitpeople/UnitpeopleVO.h"
#include "domain/query/unitpeople/UnitPeopleQuery.h"
#include "domain/dto/unitpeople/UnitPeopleDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class UnitPeopleService
{
public:
	// 分页查询所有数据
	UnitPeoplePageDTO::Wrapper listAll(const UnitPeopleQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const UnitPeopleDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const UnitPeopleDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_UNIT_PEOPLE_SERVICE_