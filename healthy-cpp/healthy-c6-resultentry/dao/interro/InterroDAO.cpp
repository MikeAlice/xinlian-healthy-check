#include "stdafx.h"
#include "InterroDAO.h"
#include "InterroMapper.h"
#include "SnowFlake.h"
#include <sstream>

uint64_t InterroDAO::insert(const InterroDO& iObj){
	// ����ѩ���㷨��������
	string id = std::to_string(SnowFlake(0, 0).nextId());
	// ����ϵͳʱ�䴴��create_time
	std::time_t now = std::time(0); // ��ȡ����ʱ��
	std::tm* timeinfo = localtime(&now); // ת��Ϊ����ʱ���tm�ṹ��
	std::stringstream ss; // ����һ���ַ���������
	ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S"); // ��tm�ṹ���ʽ��Ϊ�ַ�����
	std::string createTime = ss.str(); // ���ַ������л�ȡ�ַ���

	// ƴ��sql���`
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
