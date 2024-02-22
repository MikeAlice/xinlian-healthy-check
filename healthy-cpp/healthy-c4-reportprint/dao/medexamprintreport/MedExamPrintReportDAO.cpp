#include "stdafx.h"
#include "MedExamPrintReportDAO.h"
#include "MedExamPrintReportMapper.h"
#include <sstream>


//定义条件解析宏，减少重复代码
#define T_GROUP_PERSON_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `person_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->orderId) { \
	sql << " AND `order_id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->orderId.getValue("")); \
} \
if (query->testNum) { \
	sql << " AND `test_num`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->testNum.getValue("")); \
} \
if (query->dept) { \
	sql << " AND `dept`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->dept.getValue("")); \
} \
if (query->startDate) { \
	sql << " AND `check_date`>= STR_TO_DATE(?,'%Y-%m-%d %H:%i:%s')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->startDate.getValue("")); \
} \
if (query->endDate) { \
	sql << " AND `check_date`<= STR_TO_DATE(?,'%Y-%m-%d %H:%i:%s')"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->endDate.getValue("")); \
} \
if (query->isRecheck) { \
	sql << " AND `is_recheck`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->isRecheck.getValue(0)); \
} 

uint64_t MedExamPrintReportDAO::count(const MedExamPrintReportQuery::Wrapper& query) {
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_person";
	T_GROUP_PERSON_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return  sqlSession->executeQueryNumerical(sqlStr, params);
}     

list<MedExamPrintReportDO> MedExamPrintReportDAO::selectWithPage(const MedExamPrintReportQuery::Wrapper& query) {
	stringstream sql;
	sql << "SELECT id,person_name,sex,age,statu,print_state,sporadic_physical  FROM t_group_person";
	T_GROUP_PERSON_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	MedExamPrintReportMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<MedExamPrintReportDO, MedExamPrintReportMapper>(sqlStr, mapper, params);
}

list<MedExamPrintReportDO> MedExamPrintReportDAO::selectByName(const string& name) {
	string sql = "SELECT id,person_name,sex,age,statu,print_state,sporadic_physical FROM t_group_person WHERE `person_name` LIKE CONCAT('%',?,'%')";
	MedExamPrintReportMapper mapper;
	return sqlSession->executeQuery<MedExamPrintReportDO, MedExamPrintReportMapper>(sql, mapper, "%s", name);
}
