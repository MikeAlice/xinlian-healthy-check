#include "stdafx.h"
#include "TicketGroupNameListService.h"
#include "../../dao/Exalanding/TicketGroupNameListDAO.h"

TicketGroupNameListPageDTO::Wrapper TicketGroupNameListService::listAll(const TicketGroupNameListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = TicketGroupNameListPageDTO::createShared();

	TicketGroupNameListDAO dao;
	// 分页查询数据
	list<TicketGroupNameListDO> result = dao.selectByName(query->Unit_name);
	// 将DO转换成DTO
	for (TicketGroupNameListDO sub : result)
	{
		auto dto = TicketGroupNameListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name)
			pages->addData(dto);
		
	}
	return pages;
}

