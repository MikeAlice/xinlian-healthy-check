#include "stdafx.h"
#include "ContraindicationsMapper.h"
#include "ContraindicationsDAO.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define CONTRAINDICATIONS_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1";

uint64_t ContraindicationsDAO::count(const ContraindicationsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_dict_data";
	CONTRAINDICATIONS_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<ContraindicationsDO> ContraindicationsDAO::selectWithPage(const ContraindicationsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT title FROM t_dict_data";
	CONTRAINDICATIONS_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ContraindicationsMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ContraindicationsDO, ContraindicationsMapper>(sqlStr, mapper, params);
}
