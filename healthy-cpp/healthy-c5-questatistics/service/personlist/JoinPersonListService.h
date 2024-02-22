#pragma once

#ifndef _JOINPERSONLIST_SERVICE_
#define _JOINPERSONLIST_SERVICE_
#include <list>
#include "domain/vo/personlist/JoinPersonListVO.h"
#include "domain/query/personlist/JoinPersonListQuery.h"
#include "domain/dto/personlist/JoinPersonListDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class JoinPersonListService
{
public:
	// 分页查询所有数据
	PersonListPageDTO::Wrapper listAll(const JoinPersonListQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const JoinPersonListDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const JoinPersonListDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

