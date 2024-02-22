/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2022/01/28

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
#include "ItemResultDAO.h"
#include "ItemResultMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->itemId) { \
	sql << " AND T1.id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->itemId.getValue("")); \
} \
if (query->personId) { \
	sql << " AND T2.person_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->personId.getValue("")); \
}

//uint64_t SampleDAO::count(const SampleQuery::Wrapper& query)
//{
//	stringstream sql;
//	sql << "SELECT COUNT(*) FROM sample";
//	SAMPLE_TERAM_PARSE(query, sql);
//	string sqlStr = sql.str();
//	return sqlSession->executeQueryNumerical(sqlStr, params);
//}
//
//std::list<SampleDO> SampleDAO::selectWithPage(const SampleQuery::Wrapper& query)
//{
//	stringstream sql;
//	sql << "SELECT id,name,sex,age FROM sample";
//	SAMPLE_TERAM_PARSE(query, sql);
//	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
//	SampleMapper mapper;
//	string sqlStr = sql.str();
//	return sqlSession->executeQuery<SampleDO, SampleMapper>(sqlStr, mapper, params);
//}

uint64_t ItemResultDAO::count(const ItemResultQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_order_group_item_project T1 INNER JOIN t_depart_item_result T2 ON T1.id = T2.order_group_item_project_id";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ItemResultDO> ItemResultDAO::selectWithPage(const ItemResultQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT T1.name,T1.default_value,T1.unit_name,T2.scope FROM t_order_group_item_project T1 INNER JOIN t_depart_item_result T2 ON T1.id = T2.order_group_item_project_id";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ItemResultMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ItemResultDO, ItemResultMapper>(sqlStr, mapper, params);
}

std::list<ItemResultDO> ItemResultDAO::selectByItemAndPerson(const string& itemId, const string& personId)
{
	string sql = "SELECT T1.name,T1.default_value,T1.unit_name,T2.scope FROM t_order_group_item_project T1 INNER JOIN t_depart_item_result T2 ON T1.id = T2.order_group_item_project_id WHERE T1.id = ? AND T2.person_id = ?";
	ItemResultMapper mapper;
	return sqlSession->executeQuery<ItemResultDO, ItemResultMapper>(sql, mapper, "%s%s", itemId, personId);
}