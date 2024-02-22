#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 会跑的鱼
 @Date: 2024/1/19 17:36:29

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
#ifndef _RESULTSLIST_MAPPER_
#define _RESULTSLIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/resultslist/ResultsListDO.h"

/**
 *体检结论表字段匹配映射
 */
class ResultsListMapper : public Mapper<ResultsListDO>
{
public:
	ResultsListDO mapper(ResultSet* resultSet) const override
	{
		ResultsListDO data;
		data.setCheckId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setSex(resultSet->getString(3));
		data.setAge(resultSet->getInt(4));
		data.setIdCard(resultSet->getString(5));
		data.setCheckState(resultSet->getString(6));
		data.setDutyState(resultSet->getString(7));
		data.setDangerFactors(resultSet->getString(8));
		data.setCheckDate(resultSet->getString(9));
		data.setCheckResults(resultSet->getString(10));
		
		return data;
	}
};

#endif // !_RESULTSLIST_MAPPER_