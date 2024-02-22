#include "stdafx.h"
#include "GroupPersonInfoDAO.h"
#include "GroupPersonInfoMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define GROUP_PERSON_INFO_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->test_num) { \
	sql << " AND `test_num`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->test_num.getValue("")); \
} \

std::list<GroupPersonInfoDO> GroupPersonInfoDAO::queryInfo(const GroupPersonInfoQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT is_pass,test_num,id_card,person_name,sex,age,physical_type,sporadic_physical,dept,create_time FROM t_group_person";
	GROUP_PERSON_INFO_TERAM_PARSE(query, sql);
	GroupPersonInfoMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<GroupPersonInfoDO, GroupPersonInfoMapper>(sqlStr, mapper, params);
}