#include "stdafx.h"
#include "CountCheckService.h"

CountCheckDTO::Wrapper CountCheckService::countAll(const CountCheckQuery::Wrapper& query)
{
	// 构建返回对象
	auto count_all = CountCheckDTO::createShared();
	// 查询数据总条数
	CountCheckDAO dao;

	uint64_t count = dao.count(query);
    uint64_t count2 = dao.count2(query);

	if (count < 0&& count2 < 0)
	{
		return count_all;
	}

	// 分页查询数据
	count_all->already= count;
	count_all->yet= count2;
	return count_all;
}

