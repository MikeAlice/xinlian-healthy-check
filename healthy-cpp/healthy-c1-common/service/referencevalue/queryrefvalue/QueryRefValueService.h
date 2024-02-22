#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: chaoneng
 @Date: 2024/01/14
 @FileName: QueryRefValueService
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
#ifndef _QUERY_REF_VALUE_SERVICE_H_
#define _QUERY_REF_VALUE_SERVICE_H_
#include "domain/dto/referencevalue/RefValuePageDTO.h"
#include "domain/query/referencevalue/RefValuePageQuery.h"

class QueryRefValueService
{
public:
	// 分页查询所有数据
	RefValuePageDTO::Wrapper listAll(const RefValuePageQuery::Wrapper& query);
};
#endif
