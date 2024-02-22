#pragma once
#ifndef _TICKETGROUPNAMELIST_SERVICE_
#define _TICKETGROUPNAMELIST_SERVICE_
#include <list>
#include "domain/vo/Exalanding/TicketGroupNameListVO.h"
#include "domain/query/Exalanding/TicketGroupNameListQuery.h"
#include "domain/dto/Exalanding/TicketGroupNameListDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class TicketGroupNameListService
{
public:
	// ��ҳ��ѯ��������
	TicketGroupNameListPageDTO::Wrapper listAll(const TicketGroupNameListQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_

