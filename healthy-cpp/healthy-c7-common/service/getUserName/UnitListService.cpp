#include "stdafx.h"
#include "UnitListService.h"
#include "../../dao/getUserName/UnitListDAO.h"

UnitListPageDTO::Wrapper UnitListService::listAll(const UnitQuery::Wrapper& query)
{
	// �������ض���
	auto pages = UnitListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	UnitListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<UnitListDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
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
	// ��װDO����
	UnitListDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonName, personName, Sex, sex, Age, age, PhysicalType, physicalType, SporadicPhysical, sporadicPhysical)
		
		// ִ���������
		UnitListDAO dao;
	return dao.insert(data);
}*/


//bool UnitListService::updateData(const UnitListDTO::Wrapper& dto)
//{
//	// ��װDO����
//	UnitListDO data;
//	// 	data.setId(dto->id.getValue(0));
//	// 	data.setName(dto->name.getValue(""));
//	// 	data.setSex(dto->sex.getValue(""));
//	// 	data.setAge(dto->age.getValue(1));
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PersonName, personName, Sex, sex, Age, age, PhysicalType, physicalType, SporadicPhysical, sporadicPhysical)
//		// ִ�������޸�
//	UnitListDAO dao;
//	return dao.update(data) == 1;
//}

//bool UnitListService::removeData(uint64_t id)
//{
//	UnitListDAO dao;
//	return dao.deleteById(id) == 1;
//}
