#include "stdafx.h"
#include "GetPDMapper.h"
#include <sstream>
#include "GetPDDAO.h"

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND person_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->work_name) { \
	sql << " AND work_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->work_name.getValue("")); \
} \
if (query->id_card) { \
	sql << " AND id_card=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->id_card.getValue(0)); \
} \
if (query->id) {\
		sql << " AND id=?"; \
		SQLPARAMS_PUSH(params, "i", int, query->id.getValue(0)); \
}

uint64_t GetPDDAO::count(const GetPDQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_person";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<GetPDDO> GetPDDAO::selectWithPage(const GetPDQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT person_name,sex,work_name,id_card,age,mobile FROM t_group_person";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GetPDMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<GetPDDO, GetPDMapper>(sqlStr, mapper, params);
}
