﻿#pragma once
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
#ifndef _UPDATEINFORMATIONMAPPER_H_
#define _UPDATEINFORMATIONMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/registration/UpdateInformationDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class UpdateInformationMapper : public Mapper<UpdateInformationDO>
{
public:
	UpdateInformationDO mapper(ResultSet* resultSet) const override
	{
		UpdateInformationDO data;
		data.setPersonName(resultSet->getString(1));
		data.setSex(resultSet->getString(2));
		data.setAge(resultSet->getInt(3));
		data.setIsMarry(resultSet->getString(4));
		data.setIdCard(resultSet->getString(5));
		data.setBirth(resultSet->getString(6));
		data.setGroupId(resultSet->getString(7));
		data.setWorkName(resultSet->getString(8));
		data.setMobile(resultSet->getString(9));
		return data;
	}
};

#endif // !_UPDATEINFORMATIONMAPPER_H_