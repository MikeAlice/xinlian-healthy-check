#include "stdafx.h"
#include "RulesListService.h"
#include "../../dao/rules/RulesListDAO.h"

RulesListPageDTO::Wrapper RulesListService::listAll(const RulesListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = RulesListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	RulesListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<RulesListDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (RulesListDO sub : result)
	{
		auto dto = RulesListDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, short_name, Short_name, type,Type)
		pages->addData(dto);

	}
	return pages;
}

//RulesListPageDTO::Wrapper RulesListService::selectById(const RulesListQuery::Wrapper& query)
//{
//
//	return RulesListPageDTO::Wrapper();
//}


bool RulesListService::updateData(const RulesListDTO::Wrapper& dto)
{
	// ��װDO����
	RulesListDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Short_name, short_name, Type, type, Id, id)
		// ִ�������޸�
		RulesListDAO dao;
	return dao.update(data) == 1;
}
