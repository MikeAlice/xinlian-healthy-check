#include "stdafx.h"
#include "ReportListDAO.h"
#include "ReportListMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define REPORTLIST_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->test_num) { \
	sql << " AND `test_num`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->test_num.getValue("")); \
} \
if (query->id_card) { \
	sql << " AND `id_card`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id_card.getValue("")); \
} \
if (query->person_name) { \
	sql << " AND `person_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->person_name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
} \
if (query->check_date) { \
	sql << " AND `check_date`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->check_date.getValue("")); \
} \
if (query->check_result) { \
	sql << " AND `check_result`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->check_result.getValue("")); \
} \
if (query->physical_unit) { \
	sql << " AND `dept`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->physical_unit.getValue("")); \
} \
if (query->statu) { \
	sql << " AND statu=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->statu.getValue(0)); \
} 

uint64_t ReportListDAO::count(const ReportListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_person";
	REPORTLIST_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ReportListDO> ReportListDAO::selectWithPage(const ReportListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT test_num,id_card,person_name,sex,age,check_date,check_result,dept,statu FROM t_group_person";
	REPORTLIST_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ReportListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ReportListDO, ReportListMapper>(sqlStr, mapper, params);
}