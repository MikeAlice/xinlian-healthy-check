#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2024/01/14
 @FileName: QueryRefValueMapper
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
#ifndef _QUERY_REF_VALUE_MAPPER_
#define _QUERY_REF_VALUE_MAPPER_
#include "Mapper.h"
#include "domain/do/referencevalue/QueryRefValueDO.h"

/**
 * 基础项目配置（参考值）表字段匹配映射
 */
class QueryRefValueMapper : public Mapper<QueryRefValueDO>
{
public:
	QueryRefValueDO mapper(ResultSet* resultSet) const override
	{
		QueryRefValueDO data;
		data.setId(resultSet->getString(1));
		data.setBaseProjectId(resultSet->getString(2));
		data.setAllowSex(resultSet->getString(3));
		data.getMinAge();
		data.getMaxAge();
		data.getHealthyValue();
		data.getOccupationValue();
		data.getDepartmentId();
		data.getCreateId();
		data.getCreateTime();
		return data;
	}

private:

};

#endif
