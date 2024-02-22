#pragma once
#ifndef _TICKETGROUPNAMELIST_SERVICE_
#define _TICKETGROUPNAMELIST_SERVICE_
#include <list>
#include "domain/vo/Exalanding/TicketGroupNameListVO.h"
#include "domain/query/Exalanding/TicketGroupNameListQuery.h"
#include "domain/dto/Exalanding/TicketGroupNameListDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class TicketGroupNameListService
{
public:
	// 分页查询所有数据
	TicketGroupNameListPageDTO::Wrapper listAll(const TicketGroupNameListQuery::Wrapper& query);
};

#endif // !_SAMPLE_SERVICE_

