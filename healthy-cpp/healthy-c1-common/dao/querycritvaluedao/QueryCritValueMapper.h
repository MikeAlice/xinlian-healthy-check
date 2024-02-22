#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: stoner
 @Date: 2024/1/25 

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
#ifndef _QUERY_CRIT_VALUE_MAPPER_
#define _QUERY_CRIT_VALUE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/database/QueryCritValueDO.h"


/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class QueryCritValueMapper : public Mapper<QueryCritValueDO>
{
public:
	QueryCritValueDO mapper(ResultSet* resultSet) const override
	{
		QueryCritValueDO data;
		data.setId(resultSet->getString(1));
		data.setBaseProjectId(resultSet->getString(2));
		data.setLevel(resultSet->getString(3));
		data.setType(resultSet->getString(4));
		data.setIntervalValue(resultSet->getString(5));
		data.setAllowSex(resultSet->getString(6));
		data.setMinAge(resultSet->getInt64(7));
		data.setMaxAge(resultSet->getInt64(8));
		data.setDepartmentId(resultSet->getString(9));
		data.setCreateId(resultSet->getString(10));
		data.setCreateTime(resultSet->getString(11));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_