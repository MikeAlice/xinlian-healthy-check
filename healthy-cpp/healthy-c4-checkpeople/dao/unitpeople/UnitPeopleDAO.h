#pragma once
#ifndef _UNIT_PEOPLE_DAO_
#define _UNIT_PEOPLE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/unitpeople/UnitPeopleDO.h"
#include "../../domain/query/unitpeople/UnitPeopleQuery.h"

/**
 * 示例表数据库操作实现
 */
class UnitPeopleDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const UnitPeopleQuery::Wrapper& query);
	// 分页查询数据
	list<UnitPeopleDO> selectWithPage(const UnitPeopleQuery::Wrapper& query);
	// 通过证件号查询数据
	list<UnitPeopleDO> selectByidCard(const string& id_card);
	// 插入数据
	uint64_t insert(const UnitPeopleDO& iObj);
	// 修改数据
	int update(const UnitPeopleDO& uObj);
	// 通过ID删除数据
	int deleteById(uint64_t id);
};
#endif // !_UNIT_PEOPLE_DAO_
