#include "stdafx.h"
#include <sstream>
#include "JoinPersonListDAO.h"
#include "JoinPersonListMapper.h"


//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->testNum) { \
	sql << " AND `test_num`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->testNum.getValue("")); \
} \
if (query->name) { \
	sql << " AND name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->idCard) { \
	sql << " AND id_card=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->idCard.getValue(0)); \
}\
if (query->hazardFactor) { \
	sql << " AND hazard_factor=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->hazardFactor.getValue("")); \
}\
if (query->status) { \
	sql << " AND status=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->status.getValue("")); \
}\
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
}\
if (query->checkDate) { \
	sql << " AND check_date=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->checkDate.getValue(0)); \
}\
if (query->comments) { \
	sql << " AND comments=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->comments.getValue("")); \
}

uint64_t JoinPersonListDAO::count(const JoinPersonListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_person";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<JoinPersonListDO> JoinPersonListDAO::selectWithPage(const JoinPersonListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT test_num,name,id_card,hazard_factor,status,sex,check_date,comments FROM t_group_person";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	JoinPersonListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<JoinPersonListDO, JoinPersonListMapper>(sqlStr, mapper, params);
}

