#include "stdafx.h"
#include "TicketGroupNameListService.h"
#include "../../dao/Exalanding/TicketGroupNameListDAO.h"

TicketGroupNameListPageDTO::Wrapper TicketGroupNameListService::listAll(const TicketGroupNameListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = TicketGroupNameListPageDTO::createShared();

	TicketGroupNameListDAO dao;
	// ��ҳ��ѯ����
	list<TicketGroupNameListDO> result = dao.selectByName(query->Unit_name);
	// ��DOת����DTO
	for (TicketGroupNameListDO sub : result)
	{
		auto dto = TicketGroupNameListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name)
			pages->addData(dto);
		
	}
	return pages;
}

