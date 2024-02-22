#include "stdafx.h"
#include "LifeHistoryService.h"
#include "../../dao/unknownmodulelifehistory/LifeHistoryDAO.h"
#include "../../domain/do/unknownmodulelifehistory/LifeHistoryDO.h"
#include "../../../nacos-register/Macros.h"
#include "../../../arch-demo/Macros.h"
// #include "../../dao/GroupPerson/GroupPersonDAO.h" 待定

LifeHistoryPageDTO::Wrapper LifeHistoryService::listAll(const LifeHistoryQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = LifeHistoryPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	LifeHistoryDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<LifeHistoryDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (LifeHistoryDO sub : result)
	{
		auto dto = LifeHistoryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, person_id, Person_id, existing_children, Existing_children, allergies, Allergies, smoke_state, Smoke_state, package_every_day, Package_every_day, smoke_year, Smoke_year, drink_state, Drink_state, ml_every_day, Ml_every_day, drink_year, Drink_year, birthplace_name, Birthplace_name, family_history, Family_history)
			pages->addData(dto);
	}
	return pages;
}
