#include "stdafx.h"
#include "RulesListDAO.h"
#include "RulesListMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define RULESLIST_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->id) { \
	sql << " AND `id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} 


uint64_t RulesListDAO::count(const RulesListQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM relation_project_rules";
	RULESLIST_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<RulesListDO> RulesListDAO::selectWithPage(const RulesListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM relation_project_rules";
	RULESLIST_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	RulesListMapper mapper;
	string sqlStr = sql.str();
	cout << sqlStr << endl;
	return sqlSession->executeQuery<RulesListDO, RulesListMapper>(sqlStr, mapper, params);
}

int RulesListDAO::update(const RulesListDO& uObj)
{
	string sql = "UPDATE `relation_project_rules` SET `name`=?, `type`=?, `short_name`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s", uObj.getName(), uObj.getType(), uObj.getShort_name(), uObj.getId());
}
