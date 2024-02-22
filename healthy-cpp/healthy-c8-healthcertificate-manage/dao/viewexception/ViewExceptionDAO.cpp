#include "stdafx.h"
#include "ViewExceptionDAO.h"
#include "ViewExceptionMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define VIEW_EXCEPTION_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->health_ccertificate) { \
	sql << " AND `health_ccertificate`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->health_ccertificate.getValue("")); \
}

uint64_t ViewExceptionDAO::count(const ViewExceptionQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_certificate_manage";
	VIEW_EXCEPTION_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ViewExceptionDO> ViewExceptionDAO::selectByID(const ViewExceptionQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT exception_message FROM t_certificate_manage";
	VIEW_EXCEPTION_TERAM_PARSE(query, sql);
	ViewExceptionMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ViewExceptionDO, ViewExceptionMapper>(sqlStr, mapper, params);
}