#include "stdafx.h"
#include "BaseInfoDAO.h"
#include "BaseInfoMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE t_order_flow.order_id=t_group_person.order_id=t_group_order.order_code"; \
if (query->signingTime) { \
	sql << " AND signing_time=?"; \
	SQLPARAMS_PUSH(params, "a", std::string, query->signingTime.getValue("")); \
}\
if (query->groupUnitName) { \
	sql << " AND group_unit_name=?"; \
	SQLPARAMS_PUSH(params, "a", std::string, query->groupUnitName.getValue("")); \
}\
if (query->auditState) { \
	sql << " AND audit_state=?"; \
	SQLPARAMS_PUSH(params, "3", int, query->auditState.getValue(3)); \
}

uint64_t BaseInfoDAO::count(const BaseInfoQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(audit_state) FROM t_order_flow";//修改查询条件
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<BaseInfoDO> BaseInfoDAO::selectWithPage(const BaseInfoQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT order_name,order_id,group_unit_name,physical_type,dept_name,create_id,audit_User_name,audit_state,person_name,mobile,audit_time,sales_director_name,signing_time,signing_time \
		FROM t_order_flow,t_group_person,t_group_order";//修改查询条件
	SAMPLE_TERAM_PARSE(query, sql);
	BaseInfoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<BaseInfoDO, BaseInfoMapper>(sqlStr, mapper, params);
}
