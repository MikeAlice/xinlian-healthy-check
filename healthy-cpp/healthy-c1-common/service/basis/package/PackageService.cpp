#include "stdafx.h"
#include "PackageService.h"
#include "dao/basis/package/PackageDAO.h"
#include "domain/do/basis/PackageDO.h"

PackagePageDTO::Wrapper PackageService::listAll(const PackageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = PackagePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	PackageDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<PackageDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (PackageDO sub : result)
	{
		auto dto = PackageDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, type, Type)
		pages->addData(dto);
	}
	return pages;
}