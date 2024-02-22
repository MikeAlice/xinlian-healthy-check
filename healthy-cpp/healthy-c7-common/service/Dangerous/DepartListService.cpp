#include "DepartListService.h"
#include "../../dao/Dangerous/DepartListDAO.h"
#include "stdafx.h"
DepartListPageDTO::Wrapper DepartListService::listAll(const DepartQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = DepartListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	DepartListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<DepartListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
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
