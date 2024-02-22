#include "stdafx.h"
#include "QueryRefValueDAO.h"
#include "dao/referencevalue/queryrefvalue/QueryRefValueMapper.h"

#define REFVALUE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->id) { \
	sql << " AND `id`= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if (query->base_project_id) { \
	sql << " AND `base_project_id`= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->base_project_id.getValue("")); \
} \
if (query->allow_sex) { \
	sql << " AND `allow_sex`= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->allow_sex.getValue("")); \
} \
if (query->min_age) { \
	sql << " AND `min_age` = ?"; \
	SQLPARAMS_PUSH(params, "i", int, query->min_age.getValue(0)); \
} \
if (query->max_age) { \
	sql << " AND `max_age` = ?"; \
	SQLPARAMS_PUSH(params, "i", int, query->max_age.getValue(0)); \
} \
if (query->healthy_value) { \
	sql << " AND `healthy_value` LIKE ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, "%" + query->healthy_value.getValue("") + "%"); \
} \
if (query->occupation_value) { \
	sql << " AND `occupation_value` = ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->occupation_value.getValue("")); \
} \
if (query->department_id) { \
	sql << " AND department_id LIKE ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, "%" + query->department_id.getValue("") + "%"); \
} \
if(query->create_id){\
	sql<<" AND `create_id` = ?";\
	SQLPARAMS_PUSH(params,"s", std::string, query->create_id.getValue(""));\
}\
if(query->create_time){\
	sql<<" AND TIMESTAMPDIFF(DAY,create_time,NOW())<=?";\
	SQLPARAMS_PUSH(params,"s",std::string,query->create_time.getValue(0));\
}\

uint64_t QueryRefValueDAO::count(const RefValuePageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM relation_project_reference As rpr";
	REFVALUE_TERAM_PARSE(query, sql);
	std::string sqlStr = sql.str();
	std::cout << "Query_sql:" << sqlStr << std::endl;
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<QueryRefValueDO> QueryRefValueDAO::selectWithPage(const RefValuePageQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT * FROM relation_project_reference As rpr";
	REFVALUE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	QueryRefValueMapper mapper;
	std::string sqlStr = sql.str();
	std:cout << "selectWithPage_sql:" << sqlStr << std::endl;
	return sqlSession->executeQuery<QueryRefValueDO, QueryRefValueMapper>(sqlStr, mapper, params);
}
