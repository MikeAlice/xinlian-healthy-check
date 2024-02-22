/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:26:52

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
#include "ObtainSampleDetailsDAO.h"
#include "ObtainSampleDetailsMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->name) { \
	sql << " AND `name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->name.getValue("")); \
} \
 if (query->barcode_num) { \
	sql << " AND `barcode_num`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->barcode_num.getValue(0)); \
} \
if (query->spec) { \
	sql << " AND `spec`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->spec.getValue("")); \
} \
if (query->need_take_blood) { \
	sql << " AND `need_take_blood`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->need_take_blood.getValue(0)); \
} \
if (query->code) { \
	sql << " AND `code`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->code.getValue("")); \
} \
if (query->order_num) { \
	sql << " AND `order_num`=?"; \
	SQLPARAMS_PUSH(params, "f", float, query->order_num.getValue(0)); \
} \
if (query->is_print) { \
	sql << " AND `is_print`=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->is_print.getValue(0)); \
} \
if (query->liscode) { \
	sql << " AND `liscode`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->liscode.getValue("")); \
} \
if (query->capacity) { \
	sql << " AND `capacity`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->capacity.getValue("")); \
}
  
// 统计数据条数
uint64_t ObtainSampleDetailsDAO::count(const ObtainSampleDetailsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_sample";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

// 分页查询数据
std::list<ObtainSampleDetailsDO> ObtainSampleDetailsDAO::selectWithPage(const ObtainSampleDetailsQuery::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT name,barcode_num,spec,need_take_blood,code,order_num,is_print,liscode,capacity FROM t_sample";
	SAMPLE_TERAM_PARSE(query, sql);
	sql << " LIMIT " << ((query->pageIndex - 1) * query->pageSize) << "," << query->pageSize;
	ObtainSampleDetailsMapper mapper;
	string sqlStr = sql.str();
	return sqlSession->executeQuery<ObtainSampleDetailsDO, ObtainSampleDetailsMapper>(sqlStr, mapper, params);
}

// 通过name查询数据
std::list<ObtainSampleDetailsDO> ObtainSampleDetailsDAO::selectByName(const string& name)
{
	string sql = "SELECT name FROM t_sample WHERE `name` LIKE CONCAT('%',?,'%')";
	ObtainSampleDetailsMapper mapper;
	return sqlSession->executeQuery<ObtainSampleDetailsDO, ObtainSampleDetailsMapper>(sql, mapper, "%s", name);
}


