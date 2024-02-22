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
#include "UpdateInformationDAO.h"
#include "UpdateInformationMapper.h"
#include <sstream>

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \
SqlParams params; \
sql<<" WHERE 1=1"; \
if (query->personName) { \
	sql << " AND `person_name`=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->personName.getValue("")); \
} \
if (query->sex) { \
	sql << " AND sex=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->sex.getValue("")); \
} \
if (query->age) { \
	sql << " AND age=?"; \
	SQLPARAMS_PUSH(params, "i", int, query->age.getValue(0)); \
} \
if (query->isMarry) { \
	sql << " AND is_marry=?"; \
	SQLPARAMS_PUSH(params, "a", std::string, query->isMarry.getValue("")); \
} \
if (query->idCard) { \
	sql << " AND id_card=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->idCard.getValue("")); \
} \
if (query->birth) { \
	sql << " AND birth=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->birth.getValue("")); \
} \
if (query->groupId) { \
	sql << " AND group_id=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->groupId.getValue("")); \
} \
if (query->workName) { \
	sql << " AND work_name=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->workName.getValue("")); \
} \
if (query->mobile) { \
	sql << " AND mobile=?"; \
	SQLPARAMS_PUSH(params, "s", std::string, query->mobile.getValue("")); \
}

uint64_t UpdateInformationDAO::count(const UpdateInformationDTO::Wrapper& query)
{
	stringstream sql;
	sql << "SELECT COUNT(*) FROM t_group_person";
	SAMPLE_TERAM_PARSE(query, sql);
	string sqlStr = sql.str();
	return sqlSession->executeQueryNumerical(sqlStr, params);
}

list<UpdateInformationDO> UpdateInformationDAO::selectByIdCard(const string& idCard)
{
	string sql = "SELECT person_name,sex,age,is_marry,id_card,birth,group_id,work_name,mobile FROM t_group_person WHERE `id_card` = ?";
	UpdateInformationMapper mapper;
	return sqlSession->executeQuery<UpdateInformationDO, UpdateInformationMapper>(sql, mapper, "%s", idCard);
}



int UpdateInformationDAO::update(const UpdateInformationDO& uObj)
{
	string sql = "UPDATE `t_group_person` SET `person_name`=?, `sex`=?, `age`=?, `is_marry`=?, `id_card`=?, `birth`=?, `group_id`=?, `work_name`=?, `mobile`=? WHERE `id_card`=?";
	return sqlSession->executeUpdate(sql, "%s%s%i%s%s%s%s%s%s%s", uObj.getPersonName(), uObj.getSex(), uObj.getAge(), uObj.getIsMarry(), uObj.getIdCard(), uObj.getBirth(), uObj.getGroupId(), uObj.getWorkName(), uObj.getMobile(), uObj.getIdCard());
}
