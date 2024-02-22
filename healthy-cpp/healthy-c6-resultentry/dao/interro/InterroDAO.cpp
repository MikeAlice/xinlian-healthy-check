#include "stdafx.h"
#include "InterroDAO.h"
#include "InterroMapper.h"
#include "SnowFlake.h"
#include <sstream>

uint64_t InterroDAO::insert(const InterroDO& iObj){
	// 根据雪花算法生成主键
	string id = std::to_string(SnowFlake(0, 0).nextId());
	// 根据系统时间创建create_time
	std::time_t now = std::time(0); // 获取日历时间
	std::tm* timeinfo = localtime(&now); // 转换为本地时间的tm结构体
	std::stringstream ss; // 创建一个字符串流对象
	ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S"); // 将tm结构体格式化为字符串流
	std::string createTime = ss.str(); // 从字符串流中获取字符串

	// 拼接sql语句`
	string sql = "INSERT INTO `t_symptom` (`id`, `type`,`project_name`,`code`,`degree`,`course_time`,`person_id`,`create_id`,`create_name`,`create_time`) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
	return sqlSession->executeUpdate(sql, "%s%s%s%s%s%s%s%s%s%dt", 
		id,
		iObj.getType(),
		iObj.getProject(),
		iObj.getCode(),
		iObj.getDegree(),
		iObj.getCoursetime(),
		iObj.getPersonid(),
		iObj.getCreateid(),
		iObj.getCreatename(),
		createTime
	);
}
