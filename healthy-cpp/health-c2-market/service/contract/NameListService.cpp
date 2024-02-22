#include "stdafx.h"
#include "NameListService.h"
#include "../../dao/contract/NameListDAO.h"

NameListPageDTO::Wrapper NameListService::listAll(const NameListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = NameListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	NameListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<NameListDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
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

