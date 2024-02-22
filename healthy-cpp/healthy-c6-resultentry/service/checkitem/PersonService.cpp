#include "stdafx.h"
#include "../../dao/checkitem/PersonDAO.h"
#include "PersonService.h"

PersonPageDTO::Wrapper PersonService::listAll(const PersonQuery::Wrapper& query)
{
	// �������ض���
	auto pages = PersonPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	PersonDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	//��ѯ����
	pages->total = count;
	pages->calcPages();
	list<PersonDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (PersonDO sub : result)
	{
		auto dto = PersonDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, portfolioName, PortfolioName)
			pages->addData(dto);

	}
	return pages;
}
