#pragma once
#pragma once
#ifndef _UnitList_DAO_
#define _UnitList_DAO_
#include "BaseDAO.h"
#include "../../domain/do/getUserName/UnitListDO.h"
#include "../../domain/query/getUserName/UnitQuery.h"

/**
 * 示例表数据库操作实现
 */
class UnitListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const UnitQuery::Wrapper& query);
	// 分页查询数据
	list<UnitListDO> selectWithPage(const UnitQuery::Wrapper& query);
	// 通过姓名查询数据
	list<UnitListDO> selectByName(const string& name);
	// 插入数据
	//uint64_t insert(const UnitListDO& iObj);
	// 修改数据
	//int update(const UnitListDO& uObj);
	// 通过ID删除数据
	//int deleteById(uint64_t id);
};
#endif // !_SAMPLE_DAO_
