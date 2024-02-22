#include "stdafx.h"
#include "GroupPersonDAO.h"
#include "GroupPersonMapper.h"
#include <sstream>

//�������������꣬�����ظ�����
#define GROUP_PERSON_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `person_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->test_num) { \
	sql << " AND `test_num`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->test_num.getValue("")); \
} \
if (query->dept) { \
	sql << " AND `dept`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->dept.getValue("")); \
} \
if (query->physical_type) { \
	sql << " AND `physical_type`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->physical_type.getValue("")); \
} \
if (query->is_check) { \
	sql << " AND `is_check`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->is_check.getValue(0)); \
} \
if (query->is_recheck) { \
	sql << " AND `is_recheck`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->is_recheck.getValue(0)); \
} \
if (query->start_regist_date) { \
	sql << " AND `regist_date` > STR_TO_DATE(?, '%Y-%m-%d')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->start_regist_date.getValue("")); \
} \
if (query->finish_regist_date) { \
	sql << " AND `regist_date` < STR_TO_DATE(?, '%Y-%m-%d')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->finish_regist_date.getValue("")); \
} 

uint64_t GroupPersonDAO::count(const GroupPersonQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_person";
	GROUP_PERSON_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<GroupPersonDO> GroupPersonDAO::selectWithPage(const GroupPersonQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT person_name,sex,age,physical_type,sporadic_physical FROM t_group_person";
	GROUP_PERSON_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	GroupPersonMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<GroupPersonDO, GroupPersonMapper>(sqlStr, mapper, params);
}