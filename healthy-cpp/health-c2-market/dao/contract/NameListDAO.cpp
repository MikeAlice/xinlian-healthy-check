#include "stdafx.h"
#include "NameListDAO.h"
#include "NameListMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->auditState) { \
	sql << " AND audit_state=?"; \
	SQLPARAMS_PUSH(params, "3", int, query->auditState.getValue(3)); \
}

uint64_t NameListDAO::count(const NameListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_order_flow";//修改查询条件
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<NameListDO> NameListDAO::selectWithPage(const NameListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT signing_time,group_unit_name,audit_state FROM t_order_flow";//修改查询条件
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	NameListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<NameListDO, NameListMapper>(sqlStr, mapper, params);
}
