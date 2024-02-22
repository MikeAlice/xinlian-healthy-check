#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: ���֮��
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
 * ��ȡ�����Ŀ�����ϸ�����ݿ����ʵ��
 */
class ItemResultDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const ItemResultQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ItemResultDO> selectWithPage(const ItemResultQuery::Wrapper& query);
	
	// ͨ�������Ŀ ID ����Ա ID ��ѯ����
	list<ItemResultDO> selectByItemAndPerson(const string& itemId, const string& personId);
};
#endif // !_ITEMRESULTDAO_H_
