#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2024/01/14
 @FileName: AddRefValueDAO
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
#ifndef _ADD_REF_VALUE_DAO_
#define _ADD_REF_VALUE_DAO_
#include "BaseDAO.h"
#include "domain/do/referencevalue/AddRefValueDO.h"

class AddRefValueDAO : public BaseDAO
{
public:
	// 插入数据	负责人：超能
	uint64_t insert(const AddRefValueDO& Obj);
};
#endif