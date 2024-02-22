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
#include <iomanip>
#include "AddCritValueDAO.h"
#include <sstream>

//�������������꣬�����ظ�����
#define SAMPLE_TERAM_PARSE(query, sql) \


uint64_t AddCritValueDAO::insert(const AddCritValueDO& iObj)
{
	// ����ϵͳʱ�䴴��create_time
	std::time_t now = std::time(0); // ��ȡ����ʱ��
	std::tm* timeinfo = localtime(&now); // ת��Ϊ����ʱ���tm�ṹ��
	std::stringstream ss; // ����һ���ַ���������
	ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S"); // ��tm�ṹ���ʽ��Ϊ�ַ�����
	std::string createTime = ss.str(); // ���ַ������л�ȡ�ַ���


	string sql = "INSERT INTO `relation_project_critical` (`id`, `base_project_id`, `level`, `type`, `interval_value`, `allow_sex`, `min_age`, `max_age`, `department_id`, `create_id`, `create_time`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%i%i%s%s%dt",
		iObj.getId(),
		iObj.getBaseProjectId(),
		iObj.getLevel(),
		iObj.getType(),
		iObj.getIntervalValue(),
		iObj.getAllowSex(),
		iObj.getMinAge(),
		iObj.getMaxAge(),
		iObj.getDepartmentId(),
		iObj.getCreateId(),
		createTime
		);
}

