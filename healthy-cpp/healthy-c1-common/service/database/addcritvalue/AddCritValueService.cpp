/*
 Copyright Zero One Star. All rights reserved.

 @Author: stoner
 @Date: 2024/1/15 

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "AddCritValueService.h"
#include "../../../domain/dto/database/CritValueDTO.h"
#include "../../../domain/do/database/AddCritValueDO.h"
#include "../../../dao/addcritvaluedao/AddCritValueDAO.h"

uint64_t AddCritValueService::saveData(const CritValueDTO::Wrapper& dto)
{
	// 组装数据
	AddCritValueDO data;
	//组装DO对象数据
	data.setId(dto->id.getValue(""));
	data.setBaseProjectId(dto->baseProjectId.getValue(""));
	data.setAllowSex(dto->allowSex.getValue(""));
	data.setMinAge(dto->minAge.getValue(0));
	data.setMaxAge(dto->maxAge.getValue(0));
	data.setLevel(dto->level.getValue(""));
	data.setType(dto->type.getValue(""));
	data.setIntervalValue(dto->intervalValue.getValue(""));
	data.setDepartmentId(dto->departmentId.getValue(""));
	data.setCreateId(dto->createId.getValue(""));
	data.setCreateTime(dto->createTime.getValue(""));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		Id, id, BaseProjectId, baseProjectId, AllowSex, allowSex,
		MinAge, minAge, MaxAge, maxAge, Level, level,
		Type, type, IntervalValue, intervalValue, DepartmentId, departmentId,
		CreateId, createId, CreateTime, createTime);
	// 执行数据添加
	AddCritValueDAO dao;
	return dao.insert(data);
}