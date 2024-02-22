#include "TermService.h"
#include "stdafx.h"
#include "../../dao/term/TermListDAO.h"



TermListPageDTO::Wrapper TermService::listAll(const TermQuery::Wrapper& query)
{
	// �������ض���
	auto pages = TermListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	TermListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<TermListDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (TermListDO sub : result)
	{
		auto dto = TermListDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, officeId, OfficeId, hazardFactorsText, HazardFactorsText,
			inspectType, InspectType, content, Content, workStateText, WorkStateText)
			pages->addData(dto);

	}
	return pages;
}

uint64_t TermService::saveData(const TermListDTO::Wrapper& dto)
{
	// ��װDO����
	TermListDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, OfficeId, officeId, HazardFactorsText, hazardFactorsText,
		InspectType, inspectType, Content, content, WorkStateText, workStateText)
		// ִ���������
		TermListDAO dao;
	return dao.insert(data);
}

bool TermService::updateData(const TermListDTO::Wrapper& dto)
{
	// ��װDO����
	TermListDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, OfficeId, officeId, HazardFactorsText, hazardFactorsText,
		InspectType, inspectType, Content, content, WorkStateText, workStateText)
		// ִ�������޸�
		TermListDAO dao;
	return dao.update(data) == 1;

}

bool TermService::removeData(uint64_t id)
{
	TermListDAO dao;
	return dao.deleteById(id) == 1;

}
