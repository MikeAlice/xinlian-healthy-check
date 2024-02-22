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
#ifndef _ITEMRESULTDAO_H_
#define _ITEMRESULTDAO_H_
#include "BaseDAO.h"
#include "../../domain/do/itemResult/ItemResultDO.h"
#include "../../domain/query/itemResult/ItemResultQuery.h"

/**
 * 获取体检项目结果明细表数据库操作实现
 */
class ItemResultDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ItemResultQuery::Wrapper& query);
	// 分页查询数据
	list<ItemResultDO> selectWithPage(const ItemResultQuery::Wrapper& query);
	
	// 通过体检项目 ID 和人员 ID 查询数据
	list<ItemResultDO> selectByItemAndPerson(const string& itemId, const string& personId);
};
#endif // !_ITEMRESULTDAO_H_
