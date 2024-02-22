#include "stdafx.h"
#include "UnitPhysicalExaminationOrdersDAO.h"
#include "UnitPhysicalExaminationOrdersMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `group_unit_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->beginTime){ \
	sql << " AND date(signing_time) >= ? ";\
	SQLPARAMS_PUSH(params, "s", std::string, query->beginTime.getValue("")); \
} \
if (query->endTime){ \
	sql << " AND date(signing_time) <= ? ";\
	SQLPARAMS_PUSH(params, "s", std::string, query->endTime.getValue("")); \
} \


uint64_t UnitPhysicalExaminationOrdersDAO::count(const UnitPhysicalExaminationOrdersQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_order";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<UnitPhysicalExaminationOrdersDO> UnitPhysicalExaminationOrdersDAO::selectWithPage(const UnitPhysicalExaminationOrdersQuery::Wrapper& query)
{
	stringstream sql;
	sql << "select group_unit_name,order_code,date(signing_time),state,sporadic_physical from t_group_order ";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	UnitPhysicalExaminationOrdersMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<UnitPhysicalExaminationOrdersDO, UnitPhysicalExaminationOrdersMapper>(sqlStr, mapper, params);
}
