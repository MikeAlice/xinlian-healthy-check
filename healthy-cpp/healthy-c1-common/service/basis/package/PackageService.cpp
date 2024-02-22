#include "stdafx.h"
#include "PackageService.h"
#include "dao/basis/package/PackageDAO.h"
#include "domain/do/basis/PackageDO.h"

PackagePageDTO::Wrapper PackageService::listAll(const PackageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = PackagePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	PackageDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<PackageDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (PackageDO sub : result)
	{
		auto dto = PackageDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, type, Type)
		pages->addData(dto);
	}
	return pages;
}