#include "stdafx.h"
#include "SampleService.h"
#include "../../dao/sample/SampleDAO.h"
#include "../../domain/do/sample/SampleDO.h"

bool SampleService::updateData(const SampleDTO::Wrapper& dto)
{
	// 组装DO数据
	SampleDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Spec, spec, Code, code, Is_print, is_print, Capacity, capacity, Need_take_blood, need_take_blood, Order_num, order_num, Liscode, liscode,Id,id);
		// 执行数据修改
	SampleDAO dao;
	return dao.update(data) == 1;
}