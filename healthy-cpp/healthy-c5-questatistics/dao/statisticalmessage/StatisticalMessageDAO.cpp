#include "stdafx.h"
#include <sstream>
#include "StatisticalMessageDAO.h"
#include "StatisticalMessageMapper.h"

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->isPass) { \
	sql << " AND is_pass=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->isPass.getValue(1)); \
}

uint64_t StatisticalMessageDAO::count(const StatisticalMessageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_person";
	SqlParams params; sql << " WHERE 1=1"; if (query->isPass) {
		sql << " AND is_pass=?"; params.emplace_back(SqlParam("i", std::make_shared<int>(query->isPass.getValue(1))));
	};
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<StatisticalMessageDO> StatisticalMessageDAO::selectWithPage(const StatisticalMessageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT(COUNT(*) / (SELECT COUNT(*) FROM t_group_person)) * 100 AS pass_percentage FROM t_group_person WHERE is_pass = 1";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	StatisticalMessageMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<StatisticalMessageDO, StatisticalMessageMapper>(sqlStr, mapper, params);
}




