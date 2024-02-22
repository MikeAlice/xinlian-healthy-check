#include "AddBaseProjectService.h"
#include "../../../dao/baseproject/AddBaseProject/AddBaseProjectDAO.h"
#include "../../../domain/dto/baseproject/AddBaseProjectDTO.h"
#include "../../../domain/do/baseproject/AddBaseProjectDO.h"
/*
 Copyright Zero One Star. All rights reserved.

 @Author: firmiana
 @Date: 2024/01/23
 @FileName: AddBaseProjectService.cpp
 @version: 1.0

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
uint64_t AddBaseProjectService::saveData(const AddBaseProjectDTO::Wrapper& dto)
{
	// 组装DO数据
	AddBaseProjectDO data;
	
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
		Id, id,
		Code, code,
		Name, name,
		ShortName, short_name,
		OrderNum, order_num,
		OfficeId, office_id,
		OfficeName, office_name,
		UnitCode, unit_code,
		UnitName, unit_name,
		DefaultValue, default_value,
		ResultType, result_type,
		InConclusion, in_conclusion,
		InReport, in_report,
		RelationCode, relation_code,
		DelFlag, del_flag,
		CreateId, create_id,
		CreateTime, create_time,
		UpdateId, update_id,
		UpdateTime, update_time,
		DeleteId, delete_id,
		DeleteTime, delete_time,
		DepartmentId, department_id);

		// 执行数据添加
	AddBaseProjectDAO dao;
	return dao.insert(data);
}