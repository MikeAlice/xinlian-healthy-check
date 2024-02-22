#pragma once
#ifndef _INSERTSAMPLE_SERVICE_
#define _INSERTSAMPLE_SERVICE_
#include <list>
#include "domain/vo/sample/InsertSampleVO.h"
#include "domain/query/sample/InsertSampleQuery.h"
#include "domain/dto/sample/InsertSampleDTO.h"

/**
 * 服务实现，基础的服务实现
 */
class InsertSampleService
{
public:
	// 分页查询所有数据
	InsertSamplePageDTO::Wrapper listAll(const InsertSampleQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const InsertSampleDTO::Wrapper& dto);
	// 修改数据
	bool updateData(const InsertSampleDTO::Wrapper& dto);
	// 通过ID删除数据
	bool removeData(uint64_t id);
};

#endif // !_INSERTSAMPLE_SERVICE_

