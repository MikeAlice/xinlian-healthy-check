#include "stdafx.h"
#include "addService.h"
#include "../../dao/add/addDAO.h"

uint64_t addService::saveData(const AddUnitDTO::Wrapper& dto)
{
	// ��װDO����
	addDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, U_Name, u_name, Sex, sex, Age, age, LinkPhone, linkPhone, Name, name, Marriage , marriage, G_name, g_name)
		// ִ���������
		addDAO dao;
	return dao.insert(data);
}