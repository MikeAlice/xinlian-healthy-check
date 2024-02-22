#include "stdafx.h"
#include "AddRefValueDAO.h"
#include <iomanip>

uint64_t AddRefValueDAO::insert(const AddRefValueDO& iObj)
{
	// 根据系统时间创建create_time
	std::time_t now = std::time(0); // 获取日历时间
	std::tm* timeinfo = localtime(&now); // 转换为本地时间的tm结构体
	std::stringstream ss; // 创建一个字符串流对象
	ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S"); // 将tm结构体格式化为字符串流
	std::string create_time = ss.str(); // 从字符串流中获取字符串

	string sql = "INSERT INTO `relation_project_reference` (`id`,`base_project_id`,`allow_sex`, `min_age`, `max_age`,`healthy_value`, `occupation_value`,`department_id`,`create_id`,`create_time` ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeInsert(sql, "%s%s%s%i%i%s%s%s%s%dt",
		iObj.getId(),
		iObj.getBaseProjectId(), iObj.getAllowSex(), iObj.getMinAge(), 
		iObj.getMaxAge(), iObj.getHealthyValue(), iObj.getOccupationValue(),
		iObj.getDepartmentId(),iObj.getCreateId() ,create_time
	);
}
