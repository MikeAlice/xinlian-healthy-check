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
#include "GroupPersonDAO.h"
#include "SnowFlake.h"
#include <sstream>
#include <string>

uint64_t GroupPersonDAO::insert(const GroupPersonDO& iObj)
{
	SnowFlake sf(1, 1);
	std::string id = std::to_string(sf.nextId());
	string sql = "INSERT INTO `t_group_person` (`id`, `test_num`, `person_name`, `sex`, `id_card`, `age`, `is_marry`, `mobile`, `dept`, `physical_type`, `group_id`, `is_pass`) \
VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%i%s%s%s%s%s%i", id, iObj.getTestNum(), iObj.getPersonName(), iObj.getSex(), iObj.getIdCard(), iObj.getAge(), iObj.getIsMarry(), iObj.getMobile(),iObj.getDept(), iObj.getPhysicalType(), iObj.getGroupId(), 1);
}
