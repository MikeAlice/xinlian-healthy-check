#include "stdafx.h"
#include "SaveInfoService.h"
#include "../../dao/Exalanding/SaveInfoDAO.h"

uint64_t SampleService::saveData(const SaveInfoDTO::Wrapper& dto)
{
	// ��װDO����
	SaveInfoDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Id_card, id_card, Person_name, person_name, Sex, sex, Age, age, Mobile, mobile, Is_marry, is_marry, Is_pass ,is_pass, Physical_type, physical_type)
		// ִ���������
		SaveInfoDAO dao;
	return dao.insert(data);
}

