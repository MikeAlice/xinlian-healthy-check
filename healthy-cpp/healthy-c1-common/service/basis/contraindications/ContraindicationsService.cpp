#include "stdafx.h"
#include "dao/basis/contraindications/ContraindicationsDAO.h"
#include "domain/do/basis/ContraindicationsDO.h"
#include "ContraindicationsService.h"

ContraindicationsPageDTO::Wrapper ContraindicationsService::listAll(const ContraindicationsQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ContraindicationsPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ContraindicationsDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ContraindicationsDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ContraindicationsDO sub : result)
	{
		auto dto = ContraindicationsDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, title, Title)
		pages->addData(dto);
	}
	return pages;
}