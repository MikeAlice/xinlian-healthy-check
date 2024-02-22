#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: smartPiggy
 @Date: 2024-01-27

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
#ifndef _RESULTMAPPER_H_
#define _RESULTMAPPER_H_

#include "Mapper.h"
#include"../../domain/do/result/ResultDO.h"
/**
 * ±Ì◊÷∂Œ∆•≈‰”≥…‰
 */
class ResultMapper : public Mapper<ResultDO>
{
public:
	ResultDO mapper(ResultSet* resultSet) const override
	{
		ResultDO data;
		data.setId(resultSet->getString(1));
		data.setOfficeName(resultSet->getString(2));
		data.setGroupItemName(resultSet->getString(3));
		data.setDiagnoseSum(resultSet->getString(4));
		return data;
	}
};

#endif // !_RESULTMAPPER_H_