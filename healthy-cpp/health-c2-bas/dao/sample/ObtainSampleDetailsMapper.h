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
#ifndef _OBTAIN_SAMPLE_DETAILS_MAPPER_
#define _OBTAIN_SAMPLE_DETAILS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/sample/ObtainSampleDetailsDO.h"

/**
 * 示例表字段匹配映射
 */
class ObtainSampleDetailsMapper : public Mapper<ObtainSampleDetailsDO>
{
public:
	ObtainSampleDetailsDO mapper(ResultSet* resultSet) const override
	{
		ObtainSampleDetailsDO data;
		//data.setId(resultSet->getUInt64(1));
		data.setName(resultSet->getString(1));
		data.setBarcode_num(resultSet->getUInt(2));
		data.setSpec(resultSet->getString(3));
		data.setNeed_take_blood(resultSet->getUInt(4));
		data.setCode(resultSet->getString(5));
		data.setOrder_num(resultSet->getDouble(6));//order_num是Float32类型，但没对应
		data.setIs_print(resultSet->getUInt(7));
		data.setLiscode(resultSet->getString(8));
		data.setCapacity(resultSet->getString(9));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_