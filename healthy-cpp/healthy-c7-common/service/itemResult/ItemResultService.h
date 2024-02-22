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
#ifndef _ITEMRESULTSERVICE_H_
#define _ITEMRESULTSERVICE_H_
#include <list>
#include "domain/vo/itemResult/ItemResultVO.h"
#include "domain/query/itemResult/ItemResultQuery.h"
#include "domain/dto/itemResult/ItemResultDTO.h"

/**
 * 获取体检项目结果明细服务实现
 */
class ItemResultService
{
public:
	//// 分页查询所有数据
	//SamplePageDTO::Wrapper listAll(const SampleQuery::Wrapper& query);
	// 通过体检项目 ID 和人员 ID 查询数据
	ItemResultPageDTO::Wrapper getItemResultData(const ItemResultQuery::Wrapper& query);
};

#endif // !_ITEMRESULTSERVICE_H_

