#include "stdafx.h"
#include "GroupPersonInfoService.h"
#include "../../dao/GroupPersonInfo/GroupPersonInfoDAO.h"

GroupPersonInfoDTO::Wrapper GroupPersonInfoService::queryInfo(const GroupPersonInfoQuery::Wrapper& query)
{
	// 构建返回对象
	auto dto = GroupPersonInfoDTO::createShared();
	// 查询数据
	GroupPersonInfoDAO dao;
	list<GroupPersonInfoDO> result = dao.queryInfo(query);
	// 将DO转换成DTO
	for (GroupPersonInfoDO sub : result) {
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, is_pass, Is_pass, test_num, Test_num, id_card, Id_card, person_name, Person_name, sex, Sex, age, Age, physical_type, Physical_type, sporadic_physical, Sporadic_physical, dept, Dept, create_time, Create_time);
		return dto;
	}
	return dto;
}
