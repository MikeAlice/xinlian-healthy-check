/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "AddController.h"
#include "../../service/unitpeople/UnitPeopleService.h"
#include "../ApiDeclarativeServicesHelper.h"

Uint64JsonVO::Wrapper AddController::execAddPeople(const UnitPeopleDTO::Wrapper& dto)
{
	//响应客户端的json数据对象
	auto jvo = Uint64JsonVO::createShared();
	//参数检验
	//1、非空检验
	if (!dto->age || !dto->birth || !dto->idCard || !dto->isMarry || !dto->mobile || !dto->personName || !dto->sex)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 有效值校验
	if ( dto->age < 0 || dto->personName->empty() || dto->sex->empty() || dto->birth->empty() || dto->idCard->empty() ||
		dto->isMarry->empty() || dto->mobile->empty() )
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	UnitPeopleService service;
	//执行数据新增
	uint64_t id = service.saveData(dto);

	//响应结果
	return jvo;
}
