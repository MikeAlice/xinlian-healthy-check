#include "stdafx.h"
#include "PersonMapper.h"
#include "PersonDAO.h"
#include <sstream>


//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->id) { \
	sql << " AND t1.`id`=? "; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
}

uint64_t PersonDAO::count(const PersonQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM ";
	sql << "t_group_person AS t1 INNER JOIN t_order_group_item_project AS t2 ON t1.order_id=t2.group_order_id "
		"INNER JOIN t_order_group_item AS t3 ON t2.t_order_group_item_id = t3.id ";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " GROUP BY portfolio_project_id "
		"ORDER BY t3.name ";
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<PersonDO> PersonDAO::selectWithPage(const PersonQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT t3.portfolio_project_id,t3.name FROM ";
	sql<<"t_group_person AS t1 INNER JOIN t_order_group_item_project AS t2 ON t1.order_id=t2.group_order_id "
		"INNER JOIN t_order_group_item AS t3 ON t2.t_order_group_item_id = t3.id ";
	SAMPLE_TERAM_PARSE(query, sql);
	//sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	sql << " GROUP BY portfolio_project_id "
		"ORDER BY t3.name ";
	PersonMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PersonDO, PersonMapper>(sqlStr, mapper, params);
}
