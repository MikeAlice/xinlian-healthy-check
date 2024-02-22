#include "stdafx.h"
#include "AddRefValueDAO.h"
#include <iomanip>

uint64_t AddRefValueDAO::insert(const AddRefValueDO& iObj)
{
	// ����ϵͳʱ�䴴��create_time
	std::time_t now = std::time(0); // ��ȡ����ʱ��
	std::tm* timeinfo = localtime(&now); // ת��Ϊ����ʱ���tm�ṹ��
	std::stringstream ss; // ����һ���ַ���������
	ss << std::put_time(timeinfo, "%Y-%m-%d %H:%M:%S"); // ��tm�ṹ���ʽ��Ϊ�ַ�����
	std::string create_time = ss.str(); // ���ַ������л�ȡ�ַ���

	string sql = "INSERT INTO `relation_project_reference` (`id`,`base_project_id`,`allow_sex`, `min_age`, `max_age`,`healthy_value`, `occupation_value`,`department_id`,`create_id`,`create_time` ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

	return sqlSession->executeInsert(sql, "%s%s%s%i%i%s%s%s%s%dt",
		iObj.getId(),
		iObj.getBaseProjectId(), iObj.getAllowSex(), iObj.getMinAge(), 
		iObj.getMaxAge(), iObj.getHealthyValue(), iObj.getOccupationValue(),
		iObj.getDepartmentId(),iObj.getCreateId() ,create_time
	);
}
