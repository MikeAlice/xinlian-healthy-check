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
#ifndef _INFO_LIST_MAPPER_
#define _INFO_LIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/info-inspectionSave/InfoListDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class InfoListMapper : public Mapper<InfoListDO>
{
public:
	InfoListDO mapper(ResultSet* resultSet) const override
	{
		InfoListDO data;
		data.setId(resultSet->getUInt64(1));
		data.setPersonId(resultSet->getUInt64(2));
		data.setInspectionDoctor(resultSet->getString(3));
		data.setInspectionDate(resultSet->getString(4));
		data.setMedicalAdvice(resultSet->getString(5));
		data.setHandleOpinion(resultSet->getString(6));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_