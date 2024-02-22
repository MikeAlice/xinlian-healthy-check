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
#include "stdafx.h"
#include "ItemResultService.h"
#include "../../dao/itemResult/ItemResultDAO.h"

ItemResultPageDTO::Wrapper ItemResultService::getItemResultData(const ItemResultQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ItemResultPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ItemResultDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ItemResultDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ItemResultDO sub : result)
	{
		auto dto = ItemResultDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, defaultValue, DefaultValue, unitName, UnitName, scope, Scope)
			pages->addData(dto);

	}
	return pages;
}