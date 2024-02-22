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
#ifndef _RESULTSERVICE_H_
#define _RESULTSERVICE_H_
#include <list>
#include"../../domain/vo/result/ResultVO.h"
#include"../../domain/query/result/ResultQuery.h"
#include"../../domain/dto/result/ResultDTO.h"

/**
 * 服务实现
 */
class ResultService
{
public:
	// 分页查询该体检人诊台数据
	ResultPageDTO::Wrapper listByPersonId(const ResultQuery::Wrapper& query);
};

#endif // !_RESULTSERVICE_H_

