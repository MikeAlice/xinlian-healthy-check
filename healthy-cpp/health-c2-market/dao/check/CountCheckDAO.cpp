
#include "stdafx.h"
#include <sstream>
#include "CountCheckDAO.h"
#include "../../domain/query/check/CountCheckQuery.h"

//ͳ�������ɵĺ�ͬ
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->audit_level) { \
	sql << " AND audit_level=?"; \
	SQLPARAMS_PUSH(params, "ui", std::uint32_t, query->audit_level.getValue(0)); \
} 

//ͳ��δ�����ɵĺ�ͬ
#define SAMPLE_TERAM_PARSE1(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->audit_level) { \
	sql << " AND audit_level!=?"; \
	SQLPARAMS_PUSH(params, "ui", std::uint32_t, query->audit_level.getValue(0)); \
} 



//ͳ�������ɵĺ�ͬ
uint64_t CountCheckDAO::count(const CountCheckQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_review_content";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}




//ͳ��δ�����ɵĺ�ͬ
uint64_t CountCheckDAO::count2(const CountCheckQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_review_content";
	SAMPLE_TERAM_PARSE1(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}