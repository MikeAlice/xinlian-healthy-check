#pragma once
#ifndef _DEPART_LIST_DAO_
#define _DEPART_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Dangerous/DepartListDO.h"
#include "../../domain/query/Dangerous/DepartQuery.h"

/**
 * 示例表数据库操作实现
 */
class DepartListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const DepartQuery::Wrapper& query);
	// 分页查询数据
	list<DepartListDO> selectWithPage(const DepartQuery::Wrapper& query);
	// 通过人的id查询数据
	list<DepartListDO> selectByPersonId(const string& personId);
	// 插入数据
	//uint64_t insert(const UnitListDO& iObj);
	// 修改数据
	//int update(const UnitListDO& uObj);
	// 通过ID删除数据
	//int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_