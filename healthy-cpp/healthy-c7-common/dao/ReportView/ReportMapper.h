#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#ifndef _REPORT_MAPPER_
#define _REPORT_MAPPER_

#include "Mapper.h"
#include "domain/do/ReportView/ReportDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class ReportMapper : public Mapper<ReportDO>
{
public:
	ReportDO mapper(ResultSet* resultSet) const override
	{
		ReportDO data;
		data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(2));
		data.setSex(resultSet->getString(3));
		data.setAge(resultSet->getUInt(4));
		data.setIdCard(resultSet->getString(5));
		data.setMobile(resultSet->getString(6));
		data.setPhysicalType(resultSet->getString(7));
		data.setDept(resultSet->getString(8));
		data.setConclusion(resultSet->getString(9));
		data.setHandleOpinion(resultSet->getString(10));
		data.setInspectionDoctor(resultSet->getString(11));
		data.setInspectionDate(resultSet->getString(12));
		data.setDiagnosticUnit(resultSet->getString(13));
		return data;
	}
};

#endif // !_REPORT_MAPPER_