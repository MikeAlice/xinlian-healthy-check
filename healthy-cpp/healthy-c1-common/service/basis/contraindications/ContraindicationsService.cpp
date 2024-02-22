#include "stdafx.h"
#include "dao/basis/contraindications/ContraindicationsDAO.h"
#include "domain/do/basis/ContraindicationsDO.h"
#include "ContraindicationsService.h"

ContraindicationsPageDTO::Wrapper ContraindicationsService::listAll(const ContraindicationsQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ContraindicationsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ContraindicationsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ContraindicationsDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ContraindicationsDO sub : result)
	{
		auto dto = ContraindicationsDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, title, Title)
		pages->addData(dto);
	}
	return pages;
}