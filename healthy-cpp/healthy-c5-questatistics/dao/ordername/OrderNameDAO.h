#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 会跑的鱼
 @Date: 2024/1/19 17:36:29

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
#ifndef _ORDERNAME_DAO_
#define _ORDERNAME_DAO_
#include "BaseDAO.h"
#include "../../domain/do/resultslist/ResultsListDO.h"
#include "../../domain/query/ordername/OrderNameQuery.h"

/*
 * 体检单位订单名称表数据库操作实现
 */
class OrderNameDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const OrderNameQuery::Wrapper& query);
	// 分页查询数据
	list<ResultsListDO> selectWithPage(const OrderNameQuery::Wrapper& query);
};
#endif // !_ORDERNAME_DAO_
