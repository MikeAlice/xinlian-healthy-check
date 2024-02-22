
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
#include "CriticalListDAO.h"
#include "CriticalListMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->level) { \
	sql << " AND `level`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->level.getValue("")); \
} \
if (query->type) { \
	sql << " AND type=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->type.getValue("")); \
} \
if (query->intervalValue) { \
	sql << " AND interval_value=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->intervalValue.getValue("")); \
} \
if (query->allowSex) { \
	sql << " AND allow_sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->allowSex.getValue("")); \
} \
if (query->minAge) { \
	sql << " AND min_age=?"; \
	SQLPARAMS_PUSH(params, "i", uint32_t, query->minAge.getValue(0)); \
} \
if (query->maxAge) { \
	sql << " AND max_age=?"; \
	SQLPARAMS_PUSH(params, "i", uint32_t, query->maxAge.getValue(0)); \
}

int CriticalListDAO::update(const CriticalListDO& uObj)
{
	string sql = "UPDATE `relation_project_critical` SET `level`=?, `type`=?, `interval_value`=?, `allow_sex`=?, `min_age`=?, `max_age`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%i%i%s", uObj.getLevel(), uObj.getType(), uObj.getIntervalValue(), uObj.getAllowSex(), uObj.getMinAge(), uObj.getMaxAge(), uObj.getId());
}

int CriticalListDAO::deleteById(const CriticalListDO& uObj)
{
	string sql = "DELETE FROM `relation_project_critical` WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", uObj.getId());
}
