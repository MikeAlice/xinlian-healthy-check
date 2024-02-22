#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 咫尺之书
 @Date: 2024/01/28

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
#ifndef _ITEMRESULTMAPPER_H_
#define _ITEMRESULTMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/itemResult/ItemResultDO.h"

/**
 * 获取体检项目结果明细表字段匹配映射
 */
class ItemResultMapper : public Mapper<ItemResultDO>
{
public:
	ItemResultDO mapper(ResultSet* resultSet) const override
	{
		ItemResultDO data;
		data.setName(resultSet->getString(1));
		data.setDefaultValue(resultSet->getString(2));
		data.setUnitName(resultSet->getString(3));
		data.setScope(resultSet->getString(4));
		return data;
	}
};

#endif // !_ITEMRESULTMAPPER_H_