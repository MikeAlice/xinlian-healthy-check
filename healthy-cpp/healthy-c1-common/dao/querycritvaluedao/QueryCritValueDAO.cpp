/*
 Copyright Zero One Star. All rights reserved.

 @Author: stoner
 @Date: 2024/1/25 

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "QueryCritValueDAO.h"
#include "QueryCritValueMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define CRITVALUE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->id) { \
	sql << " AND `id`= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->id.getValue("")); \
} \
if (query->baseProjectId) { \
	sql << " AND `base_project_id`= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->baseProjectId.getValue("")); \
} \
if (query->level) { \
	sql << " AND `level`= ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->level.getValue("")); \
} \
if (query->type) { \
	sql << " AND `type` = ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->type.getValue("")); \
} \
if (query->intervalValue) { \
	sql << " AND `interval_value` = ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->intervalValue.getValue("")); \
} \
if (query->allowSex) { \
	sql << " AND `allow_sex` LIKE ?"; \
	SQLPARAMS_PUSH(params, "s", std::string,  query->allowSex.getValue("") ); \
} \
if (query->minAge) { \
	sql << " AND `min_age` = ?"; \
	SQLPARAMS_PUSH(params, "i", int, query->minAge.getValue(0)); \
} \
if (query->maxAge) { \
	sql << " AND `max_age` = ?"; \
	SQLPARAMS_PUSH(params, "i", int, query->maxAge.getValue(0)); \
} \
if (query->departmentId) { \
	sql << " AND department_id LIKE ?"; \
	SQLPARAMS_PUSH(params, "s", std::string, "%" + query->departmentId.getValue("") + "%"); \
} \
if(query->createId){\
	sql<<" AND `create_id` = ?";\
	SQLPARAMS_PUSH(params,"s", std::string, query->createId.getValue(""));\
}\
if(query->createTime){\
	sql<<" AND TIMESTAMPDIFF(DAY,create_time,NOW())<=?";\
	SQLPARAMS_PUSH(params,"s",std::string,query->createTime.getValue(0));\
}\


uint64_t QueryCritValueDAO::count(const CritValuePageQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM relation_project_critical As rpr";
	CRITVALUE_TERAM_PARSE(query, sql);
	std::string sqlStr = sql.str();
	std::cout << "Query_sql:" << sqlStr << std::endl;
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<QueryCritValueDO> QueryCritValueDAO::selectWithPage(const CritValuePageQuery::Wrapper & query)
{
	stringstream sql;
	sql << "SELECT * FROM relation_project_critical As rpr";
	CRITVALUE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	QueryCritValueMapper mapper;
	string sqlStr = sql.str();
	std:cout << "selectWithPage_sql:" << sqlStr << std::endl;
	return sqlSession->executeQuery<QueryCritValueDO, QueryCritValueMapper>(sqlStr, mapper, params);
}