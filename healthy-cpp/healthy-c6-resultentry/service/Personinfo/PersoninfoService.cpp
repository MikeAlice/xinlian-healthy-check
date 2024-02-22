#include "stdafx.h"
#include "PersoninfoService.h"
#include "../../dao/Personinfo/PersoninfoDAO.h"

PersoninfoPageDTO::Wrapper PersoninfoService::listAll(const PersoninfoQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = PersoninfoPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	PersoninfoDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<PersoninfoDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (PersoninfoDO sub : result)
	{
		auto dto = PersoninfoDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, sex, Sex, age, Age, physical_type, Physical_type, sporadic_physical, Sporadic_physical)
			pages->addData(dto);

	}
	return pages;
}
