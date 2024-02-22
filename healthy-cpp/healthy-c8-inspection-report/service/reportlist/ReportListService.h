#pragma once
#ifndef _REPORTLIST_SERVICE_
#define _REPORTLIST_SERVICE_
#include <list>
#include "domain/vo/reportlist/ReportListVO.h"
#include "domain/query/reportlist/ReportListQuery.h"
#include "domain/dto/reportlist/ReportListDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class ReportListService
{
public:
	// 分页查询所有数据
	ReportListPageDTO::Wrapper listAll(const ReportListQuery::Wrapper& query);
};

#endif // !_REPORTLIST_SERVICE_

