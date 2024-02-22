#include "DepartListService.h"
#include "../../dao/Dangerous/DepartListDAO.h"
#include "stdafx.h"
DepartListPageDTO::Wrapper DepartListService::listAll(const DepartQuery::Wrapper& query)
{
	// �������ض���
	auto pages = DepartListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	DepartListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<DepartListDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (DepartListDO sub : result)
	{
		auto dto = DepartListDTO::createShared();
		// 		dto->personName = sub.getPersonName();
		// 		dto->physicalType = sub.getPhysicalType();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		// 		dto->sporadicPhysical = sub.getSporadicPhysical();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, officeName, OfficeName, projectName, ProjectName, result, Result, scope, Scope)
			pages->addData(dto);

	}
	return pages;
}
