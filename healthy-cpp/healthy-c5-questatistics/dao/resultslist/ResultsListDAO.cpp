/*
 Copyright Zero One Star. All rights reserved.

 @Author: 会跑的鱼
 @Date: 2024/1/19 17:36:29

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
#include "ResultsListDAO.h"
#include "ResultsListMapper.h"
#include <sstream>
//获取体检结果
//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->checkResults) { \
	sql << " AND comments=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->checkResults.getValue("")); \
}
//if (query->name) { \
	sql << " AND `person_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \

uint64_t ResultsListDAO::count(const ResultsListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_person s LEFT JOIN t_conclusion c on s.id = c.id";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

std::list<ResultsListDO> ResultsListDAO::selectWithPage(const ResultsListQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT s.test_num,s.person_name,s.sex,s.age,s.id_card,s.statu,s. work_state_text,s.hazard_factors_text,s.check_date,c.comments \
			FROM t_group_person s LEFT JOIN t_conclusion c on s.id = c.id";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ResultsListMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ResultsListDO, ResultsListMapper>(sqlStr, mapper, params);
}

//std::list<ResultsListDO> ResultsListDAO::selectByName(const string& name)
//{
//	string sql = "SELECT id,name,sex,age FROM sample WHERE `name` LIKE CONCAT('%',?,'%')";
//	ResultsListMapper mapper;
//	return sqlSession->executeQuery<ResultsListDO, ResultsListMapper>(sql, mapper, "%s", name);
//}

