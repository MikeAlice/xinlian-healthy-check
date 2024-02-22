#pragma once

#ifndef _STATISTICALMESSAGE_SERVICE_
#define _STATISTICALMESSAGE_SERVICE_
#include <list>
#include "domain/vo/statisticalmessage/StatisticalMessageVO.h"
#include "domain/query/statisticalmessage/StatisticalMessageQuery.h"
#include "domain/dto/statisticalmessage/StatisticalMessageDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class StatisticalMessageService
{
public:
	// 分页查询所有数据
	StatisticalMessagePageDTO::Wrapper listAll(const StatisticalMessageQuery::Wrapper& query);
	// 保存数据
	//uint64_t saveData(const JoinPersonListDTO::Wrapper& dto);
	// 修改数据
	//bool updateData(const JoinPersonListDTO::Wrapper& dto);
	// 通过ID删除数据
	//bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

