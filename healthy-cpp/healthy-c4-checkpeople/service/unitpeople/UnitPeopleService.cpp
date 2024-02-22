#include "stdafx.h"
#include "../../dao/unitpeople/UnitPeopleDAO.h"
#include "UnitPeopleService.h"

UnitPeoplePageDTO::Wrapper UnitPeopleService::listAll(const UnitPeopleQuery::Wrapper& query)
{
	 //�������ض���
	auto pages = UnitPeoplePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	 //��ѯ����������
	UnitPeopleDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<UnitPeopleDO> result = dao.selectWithPage(query);
	 //��DOת����DTO
	for (UnitPeopleDO sub : result)
	{
		auto dto = UnitPeopleDTO::createShared();
		
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, personName, PersonName, sex, Sex, idCard, IdCard, birth, Birth, age, Age, isMarry, IsMarry, mobile, Mobile)
		pages->addData(dto);

	}
	return pages;
}

uint64_t UnitPeopleService::saveData(const UnitPeopleDTO::Wrapper& dto)
{
	// ��װDO����
	UnitPeopleDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonName, personName, Sex, sex, IdCard, idCard, Birth, birth, Age, age, IsMarry, isMarry, Mobile, mobile);
		// ִ���������
	UnitPeopleDAO dao;
	return dao.insert(data);
}
