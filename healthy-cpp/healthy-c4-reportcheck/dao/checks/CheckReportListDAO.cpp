#include "stdafx.h"
#include "CheckReportListDAO.h"
#include "CheckReportListMapper.h"
#include <sstream>

/*
* 获取报告列表数据实体
* 负责人 Z
*/
//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->type){ \
	sql << " AND `physical_type`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->type.getValue("")); \
} \
if (query->person_name) { \
	sql << " AND `person_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->person_name.getValue("")); \
} \
if (query->order_id) { \
	sql << " AND `order_id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->order_id.getValue("")); \
} \
if (query->test_num) { \
	sql << " AND `test_num`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->test_num.getValue("")); \
}\
if (query->unit_id) {\
		sql << " AND `unit_id`=?"; \
		SQLPARAMS_PUSH(params, "s", std::string, query->unit_id.getValue("")); \
} \
if (query->statu) {\
		sql << " AND `statu`=?"; \
		SQLPARAMS_PUSH(params, "b", bool, query->statu.getValue("")); \
} \
if (query->is_recheck) {\
		sql << " AND `is_recheck`=?"; \
		SQLPARAMS_PUSH(params, "b", bool, query->is_recheck.getValue("")); \
} \
if (query->stardate && query->enddate) {\
		sql << " AND `check_date` BETWEEN STR_TO_DATE(?,'%Y-%m-%d %H:%i:%s') AND STR_TO_DATE(?,'%Y-%m-%d %H:%i:%s')";\
		SQLPARAMS_PUSH(params, "s", std::string, query->stardate.getValue("")); \
		SQLPARAMS_PUSH(params, "s", std::string, query->enddate.getValue("")); \
}


uint64_t CheckReportListDAO::count(const CheckReportQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_person";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<CheckReportListDO> CheckReportListDAO::selectWithPage(const CheckReportQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT id,person_name,sex,age,statu,print_state,sporadic_physical FROM  t_group_person";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	CheckReportListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<CheckReportListDO, CheckReportListMapper>(sqlStr, mapper, params);
}
