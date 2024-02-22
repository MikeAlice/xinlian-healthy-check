/*
 Copyright Zero One Star. All rights reserved.

 @Author: กฃบร
 @Date: 2024/01/27 20:48:57

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
#include "UnitReportDAO.h"
#include "UnitReportMapper.h"

list<UnitReportDO> UnitReportDAO::selectAll()
{
	string sql = "SELECT code, physical_unit, physical_date, physical_project, concluding_observations, physical_type, entrust_unit, physical_number, evaluation_basis FROM t_unit_report";
	UnitReportMapper mapper;                                                            
	auto result = sqlSession->executeQuery<UnitReportDO, UnitReportMapper>(sql, mapper);
	return result;
}