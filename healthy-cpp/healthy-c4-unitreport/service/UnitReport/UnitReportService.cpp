/*
 Copyright Zero One Star. All rights reserved.

 @Author: 。好
 @Date: 2024/01/27 20:32:01

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
#include "stdafx.h"
#include "UnitReportService.h"
#include "../../dao/UnitReport/UnitReportDAO.h"

UnitReportListDTO::Wrapper UnitReportService::listAll()
{
	// 构建返回对象
	auto result = UnitReportListDTO::createShared();

	// 调用DAO层
	UnitReportDAO dao;
	list<UnitReportDO> listDO = dao.selectAll();

	// 将DO转换为DTO
	for (auto DO : listDO)
	{
		auto dto = UnitReportDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, DO, code, CCode, physical_unit, PhysicalUnit, physical_date, PhysicalDate, physical_project, PhysicalProject, concluding_observations, ConcludingObservations, 
							     physical_type, PhysicalType, entrust_unit, EntrustUnit, physical_number, PhysicalNumber, evaluation_basis, EvaluationBasis);
		result->push(dto);
	}
	return result;
}