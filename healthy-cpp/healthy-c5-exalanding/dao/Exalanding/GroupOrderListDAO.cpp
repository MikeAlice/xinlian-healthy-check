#include"dao/Exalanding/GroupOrderListDAO.h"

#include "stdafx.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->sex) { \
	sql << " AND `sex`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->groupUnitName) { \
	sql << " AND group_unit_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->groupUnitName.getValue("")); \
} \
if (query->groupName) { \
	sql << " AND name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->groupName.getValue("")); \
}

uint64_t GroupOrderListDAO::count(const GroupOrderListQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_order";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<GroupOrderListDO> GroupOrderListDAO::selectWithPage(const GroupOrderListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECTt_group_person.sex,t_group_order.group_unit_name,t_order_group.name\
	FROM  t_group_person\
	JOIN t_group_order ON t_group_person.order_id = t_group_order.id\
    JOIN t_order_group ON t_group_person.group_id = t_order_group.id";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GroupOrderListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<GroupOrderListDO, GroupOrderListMapper>(sqlStr, mapper, params);
}
