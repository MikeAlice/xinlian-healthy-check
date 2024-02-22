#include "stdafx.h"
#include "GroupPersonService.h"
#include "../../dao/GroupPerson/GroupPersonDAO.h"

GroupPersonPageDTO::Wrapper GroupPersonService::listAll(const GroupPersonQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GroupPersonPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	GroupPersonDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<GroupPersonDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (GroupPersonDO sub : result)
	{
		auto dto = GroupPersonDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, sex, Sex, age, Age, physical_type, Physical_type, sporadic_physical, Sporadic_physical)
			pages->addData(dto);

	}
	return pages;
}
