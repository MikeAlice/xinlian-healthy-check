#pragma once

#ifndef _SELECTBASEPROJECTDAO_H_
#define _SELECTBASEPROJECTDAO_H_
#include "BaseDAO.h"
#include "../../../domain/do/baseproject/SelectBaseProjectDO.h"
#include "../../../domain/query/baseproject/SelectBaseProjectQuery.h"

/**
 * 示例表数据库操作实现
 */
class SelectBaseProjectDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const SelectBaseProjectQuery::Wrapper& query);

	std::list<SelectBaseProjectDO> selectWithPage(const SelectBaseProjectQuery::Wrapper& query);
	// 通过id查询数据
	list<SelectBaseProjectDO> selectById(const string& id);
};
#endif // !_SELECTBASEPROJECTDAO_H_
