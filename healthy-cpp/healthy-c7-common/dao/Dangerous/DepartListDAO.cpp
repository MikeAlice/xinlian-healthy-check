#include "DepartListDAO.h"
#include "stdafx.h"
#include "DepartListMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->personId) { \
	sql << " AND `person_id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->personId.getValue("")); \
} \


uint64_t DepartListDAO::count(const DepartQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_depart_item_result";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr,params);
}

list<DepartListDO> DepartListDAO::selectWithPage(const DepartQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT office_name,order_group_item_project_name,result,scope FROM t_depart_item_result";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	DepartListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<DepartListDO, DepartListMapper>(sqlStr, mapper, params);
}

list<DepartListDO> DepartListDAO::selectByPersonId(const string& personId)
{
	string sql = "SELECT office_name,order_group_item_project_name,result,scope FROM t_depart_item_result WHERE person_id = ?";
	DepartListMapper mapper;
	return sqlSession->executeQuery<DepartListDO, DepartListMapper>(sql, mapper, "%s", personId);
}
