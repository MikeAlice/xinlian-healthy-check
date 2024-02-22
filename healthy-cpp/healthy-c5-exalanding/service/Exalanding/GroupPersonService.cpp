#include "stdafx.h"
#include "GroupPersonService.h"
#include "../../dao/Exalanding/GroupPersonDAO.h"

uint64_t GroupPersonService::saveData(const GroupPersonDTO::Wrapper& dto)
{
	// 组装DO数据
	GroupPersonDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, TestNum, testNum, PersonName, personName, Sex, sex, IdCard, idCard, Age, age, IsMarry, isMarry, Mobile, mobile, Dept, dept, PhysicalType, physicalType, GroupId, groupId)
		// 执行数据添加
		GroupPersonDAO dao;
	return dao.insert(data);
}
