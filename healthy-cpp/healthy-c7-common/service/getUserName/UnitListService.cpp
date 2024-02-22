#include "stdafx.h"
#include "UnitListService.h"
#include "../../dao/getUserName/UnitListDAO.h"

UnitListPageDTO::Wrapper UnitListService::listAll(const UnitQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = UnitListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	UnitListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<UnitListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (UnitListDO sub : result)
	{
		auto dto = UnitListDTO::createShared();
		// 		dto->personName = sub.getPersonName();
		// 		dto->physicalType = sub.getPhysicalType();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		// 		dto->sporadicPhysical = sub.getSporadicPhysical();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, personName, PersonName, sex, Sex, age, Age, physicalType, PhysicalType, sporadicPhysical, SporadicPhysical)
			pages->addData(dto);

	}
	return pages;
}



/*
uint64_t UnitListService::saveData(const UnitListDTO::Wrapper& dto)
{
	// 组装DO数据
	UnitListDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonName, personName, Sex, sex, Age, age, PhysicalType, physicalType, SporadicPhysical, sporadicPhysical)
		
		// 执行数据添加
		UnitListDAO dao;
	return dao.insert(data);
}*/


//bool UnitListService::updateData(const UnitListDTO::Wrapper& dto)
//{
//	// 组装DO数据
//	UnitListDO data;
//	// 	data.setId(dto->id.getValue(0));
//	// 	data.setName(dto->name.getValue(""));
//	// 	data.setSex(dto->sex.getValue(""));
//	// 	data.setAge(dto->age.getValue(1));
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonName, personName, Sex, sex, Age, age, PhysicalType, physicalType, SporadicPhysical, sporadicPhysical)
//		// 执行数据修改
//	UnitListDAO dao;
//	return dao.update(data) == 1;
//}

//bool UnitListService::removeData(uint64_t id)
//{
//	UnitListDAO dao;
//	return dao.deleteById(id) == 1;
//}
