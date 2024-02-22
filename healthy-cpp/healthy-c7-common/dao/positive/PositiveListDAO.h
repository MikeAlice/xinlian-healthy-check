#pragma once
#ifndef _POSITIVE_LIST_DAO_
#define _POSITIVE_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/positive/PositiveListDO.h"
#include "../../domain/query/positive/positiveQuery.h"

/**
 * 示例表数据库操作实现
 */
class PositiveListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const PositiveQuery::Wrapper& query);
	// 分页查询数据
	list<PositiveListDO> selectWithPage(const PositiveQuery::Wrapper& query);
	// 通过姓名查询数据
	list<PositiveListDO> selectByName(const string& name);
	// 插入数据
	uint64_t insert(const PositiveListDO& iObj);
	// 修改数据
	int update(const PositiveListDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_POSITIVE_LIST_DAO_
