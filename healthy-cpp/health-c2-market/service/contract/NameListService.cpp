#include "stdafx.h"
#include "NameListService.h"
#include "../../dao/contract/NameListDAO.h"

NameListPageDTO::Wrapper NameListService::listAll(const NameListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = NameListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	NameListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<NameListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (NameListDO sub : result)
	{
		auto dto = NameListDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, signingTime, SigningTime, groupUnitName, GroupUnitName, auditState, AuditState)
		pages->addData(dto);

	}
	return pages;
}

