#include "PositiveListDAO.h"
#include "stdafx.h"
#include "PositiveListMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->personName) { \
	sql << " AND `person_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->personName.getValue("")); \
} \
if (query->officeName) { \
	sql << " AND t_depart_item_result.office_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->officeName.getValue("")); \
} \
if (query->checkDate) { \
	sql << " AND DATE(t_depart_item_result.check_date)=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->checkDate.getValue("")); \
}\
if (query->isNormal) { \
	sql << " AND t_depart_item_result.positive=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->isNormal.getValue(0)); \
}


uint64_t PositiveListDAO::count(const PositiveQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_person JOIN t_depart_item_result ON t_group_person.id = t_depart_item_result.person_id";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<PositiveListDO> PositiveListDAO::selectWithPage(const PositiveQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT  t_group_person.id ,t_group_person.person_name,t_group_person.test_num,t_depart_item_result.office_name,t_depart_item_result.order_group_item_project_name,t_depart_item_result.result,t_depart_item_result.unit_name,t_depart_item_result.scope,t_depart_item_result.crisis_degree,t_depart_item_result.check_date AS checkDate FROM  t_depart_item_result JOIN t_group_person ON t_group_person.id = t_depart_item_result.person_id";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	PositiveListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PositiveListDO, PositiveListMapper>(sqlStr, mapper, params);
}


