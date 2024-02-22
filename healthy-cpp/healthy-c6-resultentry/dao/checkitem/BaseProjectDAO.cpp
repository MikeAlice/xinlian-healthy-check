#include "stdafx.h"
#include "BaseProejctMapper.h"
#include "BaseProjectDAO.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->portfolioId) { \
	sql << " AND p.`id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->portfolioId.getValue("")); \
}

uint64_t BaseProjectDAO::count(const BaseProjectQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM ";
	sql << "t_portfolio_project AS p INNER JOIN relation_base_portfolio AS r1 ON p.id=r1.portfolio_project_id INNER JOIN t_base_project AS b ON b.id=r1.base_project_id LEFT JOIN relation_project_reference AS r2 ON r2.base_project_id=b.id ";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<BaseProjectDO> BaseProjectDAO::selectWithPage(const BaseProjectQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT b.code,b.name,b.unit_name,r2.healthy_value,b.default_value,b.result_type FROM ";
	sql << "t_portfolio_project AS p INNER JOIN relation_base_portfolio AS r1 ON p.id=r1.portfolio_project_id INNER JOIN t_base_project AS b ON b.id=r1.base_project_id LEFT JOIN relation_project_reference AS r2 ON r2.base_project_id=b.id ";
	SAMPLE_TERAM_PARSE(query, sql);
	//sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	BaseProjectMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<BaseProjectDO, BaseProjectMapper>(sqlStr, mapper, params);
}



