#include "stdafx.h"
#include "../../dao/unitpeople/UnitPeopleDAO.h"
#include "UnitPeopleService.h"

UnitPeoplePageDTO::Wrapper UnitPeopleService::listAll(const UnitPeopleQuery::Wrapper& query)
{
	 //构建返回对象
	auto pages = UnitPeoplePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	 //查询数据总条数
	UnitPeopleDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<UnitPeopleDO> result = dao.selectWithPage(query);
	 //将DO转换成DTO
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
	// 组装DO数据
	UnitPeopleDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonName, personName, Sex, sex, IdCard, idCard, Birth, birth, Age, age, IsMarry, isMarry, Mobile, mobile);
		// 执行数据添加
	UnitPeopleDAO dao;
	return dao.insert(data);
}
