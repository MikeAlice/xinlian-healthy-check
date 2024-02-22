/*
 Copyright Zero One Star. All rights reserved.

 @Author: smartPiggy
 @Date: 2024-01-27

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
#include"./ResultDAO.h"
#include"./ResultMapper.h"
#include <sstream>

uint64_t ResultDAO::count(const ResultQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_depart_result";
	string sqlStr = sql.str();
	SqlParams params;
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<ResultDO> ResultDAO::selectWithPage(const ResultQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT id,office_name,group_item_name,diagnose_sum FROM t_depart_result";
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ResultMapper mapper;
	SqlParams params;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ResultDO, ResultMapper>(sqlStr, mapper, params);
}

list<ResultDO> ResultDAO::selectByPersonId(const ResultQuery::Wrapper& query, const string& PersonId)
{
	stringstream sql;
	sql << "SELECT ROW_NUMBER() OVER (ORDER BY office_id) AS '#',office_name AS '科室',group_item_name AS '检查项目',diagnose_sum AS '体检小结' FROM t_depart_result WHERE person_id = ?";
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ResultMapper mapper;
	SqlParams params;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ResultDO, ResultMapper>(sqlStr, mapper, "%s", PersonId);
}


