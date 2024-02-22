#include "stdafx.h"
#include "PersoninfoService.h"
#include "../../dao/Personinfo/PersoninfoDAO.h"

PersoninfoPageDTO::Wrapper PersoninfoService::listAll(const PersoninfoQuery::Wrapper& query)
{
	// �������ض���
	auto pages = PersoninfoPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	PersoninfoDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<PersoninfoDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (PersoninfoDO sub : result)
	{
		auto dto = PersoninfoDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, sex, Sex, age, Age, physical_type, Physical_type, sporadic_physical, Sporadic_physical)
			pages->addData(dto);

	}
	return pages;
}
