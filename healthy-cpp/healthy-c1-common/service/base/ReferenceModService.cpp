#include "stdafx.h"
#include "../../dao/base/ReferenceModDAO.h"
#include "ReferenceModService.h"

uint64_t ReferenceModService::saveData(const ReferenceModDTO::Wrapper& dto)
{
	return 0;
}

bool ReferenceModService::updateData(const ReferenceModDTO::Wrapper& dto)
{
	// ��װDO����
	ReferenceModDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, AllowSex, allowSex, MinAge, minAge, MaxAge, maxAge, HealthyValue, healthyValue, OccupationValue, occupationValue, Id, id)
		// ִ�������޸�
		ReferenceModDAO dao;
	return dao.update(data) == 1;
}

