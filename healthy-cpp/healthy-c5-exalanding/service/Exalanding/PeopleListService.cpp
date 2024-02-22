#include "stdafx.h"
#include "PeopleListService.h"
#include "../../dao/Exalanding/PeopleListDAO.h"

PeopleListPageDTO::Wrapper PeopleListService::listAll(const PeopleListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = PeopleListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	PeopleListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<PeopleListDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (PeopleListDO sub : result)
	{
		auto dto = PeopleListDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, person_name, Person_name, sex, Sex, age, Age, jc_type, Jc_type, sporadic_physical, Sporadic_physical)
			pages->addData(dto);
		
	}
	return pages;
}

uint64_t PeopleListService::saveData(const PeopleListDTO::Wrapper& dto)
{
	// ��װDO����
	PeopleListDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Person_name, person_name, Sex, sex, Age, age, Jc_type, jc_type, Sporadic_physical, sporadic_physical)
		// ִ���������
		PeopleListDAO dao;
	return dao.insert(data);
}

bool PeopleListService::updateData(const PeopleListDTO::Wrapper& dto)
{
	// ��װDO����
	PeopleListDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Person_name, person_name, Sex, sex, Age, age, Jc_type, jc_type, Sporadic_physical, sporadic_physical)
		// ִ�������޸�
		PeopleListDAO dao;
	return dao.update(data) == 1;
}

bool PeopleListService::removeData(uint64_t id)
{
	PeopleListDAO dao;
	return dao.deleteById(id) == 1;
}

