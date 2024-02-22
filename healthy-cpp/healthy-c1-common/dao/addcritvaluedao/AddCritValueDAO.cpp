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

//定义条件解析宏，减少重复代码
#define SAMPLE_TERAM_PARSE(query, sql) \


uint64_t AddCritValueDAO::insert(const AddCritValueDO& iObj)
{
	// 根据系统时间创建create_time
	std::time_t now = std::time(0); // 获取日历时间
	std::tm* timeinfo = localtime(&now); // 转换为本地时间的tm结构体
	std::stringstream ss; // 创建一个字符串流对象
	ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S"); // 将tm结构体格式化为字符串流
	std::string createTime = ss.str(); // 从字符串流中获取字符串


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

