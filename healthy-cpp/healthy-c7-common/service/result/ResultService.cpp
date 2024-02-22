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
#include "stdafx.h"
#include"ResultService.h"
#include"../../dao/result/ResultDAO.h"

ResultPageDTO::Wrapper ResultService::listByPersonId(const ResultQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ResultPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	
	// 查询数据总条数
	ResultDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ResultDO> result = dao.selectByPersonId(query, query->personId);
	// 将DO转换成DTO
	for (ResultDO sub : result)
	{
		auto dto = ResultDTO::createShared();
		dto->id = sub.getId();
		dto->officeName = sub.getOfficeName();
		dto->groupItemName = sub.getGroupItemName();
		dto->diagnoseSum = sub.getDiagnoseSum();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, officeName, OfficeName, groupItemName, GroupItemName, diagnoseSum, DiagnoseSum)
			pages->addData(dto);

	}
	return pages;
}
