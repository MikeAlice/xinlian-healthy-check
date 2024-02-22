#include "stdafx.h"
#include "PackageMapper.h"
#include "PackageDAO.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define PACKAGE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->type) { \
	sql << " AND type=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->type.getValue("")); \
}

uint64_t PackageDAO::count(const PackageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_combo";
	PACKAGE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<PackageDO> PackageDAO::selectWithPage(const PackageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT name,type FROM t_combo";
	PACKAGE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	PackageMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PackageDO, PackageMapper>(sqlStr, mapper, params);
}

list<PackageDO> PackageDAO::selectByName(const string& name)
{
	string sql = "SELECT name,type FROM t_combo WHERE `name` LIKE CONCAT('%',?,'%')";
	PackageMapper mapper;
	return sqlSession->executeQuery<PackageDO, PackageMapper>(sql, mapper, "%s", name);
}

list<PackageDO> PackageDAO::selectByType(const string& type)
{
	string sql = "SELECT name,type FROM t_combo WHERE type=?";
	PackageMapper mapper;
	return sqlSession->executeQuery<PackageDO, PackageMapper>(sql, mapper, "%s", type);
}
