#include "stdafx.h"
#include "PastMedicalHistoryDAO.h"
#include "PastMedicalHistoryMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define GROUP_PERSON_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->person_id) { \
	sql << " AND `person_id`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->person_id.getValue("")); \
} \

uint64_t PastMedicalHistoryDAO::count(const PastMedicalHistoryQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_interrogation";
	GROUP_PERSON_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<PastMedicalHistoryDO> PastMedicalHistoryDAO::selectWithPage(const PastMedicalHistoryQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT person_id, abortion, premature, death, abnormal_fetus, menstrual_history, menstrual_info, allergies, allergies_info, past_medical_history, past_medical_history_other_info FROM t_interrogation";
	GROUP_PERSON_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	PastMedicalHistoryMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<PastMedicalHistoryDO, PastMedicalHistoryMapper>(sqlStr, mapper, params);
}