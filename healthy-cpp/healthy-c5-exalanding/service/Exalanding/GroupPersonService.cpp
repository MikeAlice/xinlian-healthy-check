#include "stdafx.h"
#include "GroupPersonService.h"
#include "../../dao/Exalanding/GroupPersonDAO.h"

uint64_t GroupPersonService::saveData(const GroupPersonDTO::Wrapper& dto)
{
	// ��װDO����
	GroupPersonDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, TestNum, testNum, PersonName, personName, Sex, sex, IdCard, idCard, Age, age, IsMarry, isMarry, Mobile, mobile, Dept, dept, PhysicalType, physicalType, GroupId, groupId)
		// ִ���������
		GroupPersonDAO dao;
	return dao.insert(data);
}
