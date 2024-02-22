#include "stdafx.h"
#include "HealthCertificateListDAO.h"
#include "HealthCertificateListMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define HEALTH_CERTIFICATE_LIST_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->health_ccertificate) { \
	sql << " AND `health_ccertificate`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->health_ccertificate.getValue("")); \
} \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
if (query->sex) { \
	sql << " AND `sex`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
} \
if (query->print_state) { \
	sql << " AND `print_state`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->print_state.getValue(0)); \
} \
if (query->is_upload) { \
	sql << " AND `is_upload`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->is_upload.getValue(0)); \
} \
if (query->print_state) { \
	sql << " AND `print_state`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->print_state.getValue(0)); \
} \
if (query->start_date) { \
	sql << " AND `date_of_issue`>=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->start_date.getValue("")); \
} \
if (query->end_date) { \
	sql << " AND `date_of_issue`<=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->end_date.getValue("")); \
} \



uint64_t HealthCertificateListDAO::count(const HealthCertificateListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_certificate_manage";
	HEALTH_CERTIFICATE_LIST_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<HealthCertificateListDO> HealthCertificateListDAO::selectWithPage(const HealthCertificateListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT health_ccertificate,name,sex,age,term_of_validity,unit_of_issue,is_upload FROM t_certificate_manage";
	HEALTH_CERTIFICATE_LIST_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	HealthCertificateListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<HealthCertificateListDO, HealthCertificateListMapper>(sqlStr, mapper, params);
}