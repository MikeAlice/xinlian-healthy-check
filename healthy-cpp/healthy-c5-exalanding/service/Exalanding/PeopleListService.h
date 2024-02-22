#pragma once
#ifndef _PEOPLELIST_SERVICE_
#define _PEOPLELIST_SERVICE_
#include <list>
#include "domain/vo/Exalanding/PeopleListVO.h"
#include "domain/query/Exalanding/PeopleListQuery.h"
#include "domain/dto/Exalanding/PeopleListDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class PeopleListService
{
public:
	// 分页查询所有数据
	PeopleListPageDTO::Wrapper listAll(const PeopleListQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const PeopleListDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const PeopleListDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

