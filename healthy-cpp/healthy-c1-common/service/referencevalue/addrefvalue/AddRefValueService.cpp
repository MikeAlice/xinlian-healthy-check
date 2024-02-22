#include "AddRefValueService.h"
#include "dao/referencevalue/addrefvalue/AddRefValueDAO.h"
#include "domain/dto/referencevalue/AddRefValueDTO.h"
#include "domain/do/referencevalue/AddRefValueDO.h"

uint64_t AddRefValueService::saveData(const AddRefValueDTO::Wrapper& dto)
{
	// 组装数据
	AddRefValueDO data;
	//组装DO对象数据
	data.setId(dto->id.getValue(""));
	data.setBaseProjectId(dto->base_project_id.getValue(""));
	data.setAllowSex(dto->allow_sex.getValue(""));
	data.setMinAge(dto->min_age.getValue(0));
	data.setMaxAge(dto->max_age.getValue(0));
	data.setHealthyValue(dto->healthy_value.getValue(""));
	data.setOccupationValue(dto->occupation_value.getValue(""));
	data.setDepartmentId(dto->department_id.getValue(""));
	data.setCreateId(dto->create_id.getValue(""));
	data.setCreateTime(dto->create_time.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		Id, id, BaseProjectId, base_project_id, AllowSex, allow_sex,
		MinAge, min_age, MaxAge, max_age, HealthyValue, healthy_value,
		OccupationValue, occupation_value, DepartmentId, department_id,
		CreateId, create_id, CreateTime, create_time);
	// 执行数据添加
	AddRefValueDAO dao;
	return dao.insert(data);
}
