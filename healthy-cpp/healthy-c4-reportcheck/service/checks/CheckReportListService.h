#pragma once
#ifndef _CHECKREPORTLIST_SERVICE_
#define _CHECKREPORTLIST_SERVICE_
#include <list>
#include "domain/vo/checks/CheckReportVO.h"
#include "domain/query/checks/CheckReportQuery.h"
#include "domain/dto/checks/CheckReportListDTO.h"

/**
 * 获取单位列表服务实现
 */
class CheckReportListService
{
public:
	// 分页查询所有数据
	CheckReportListPageDTO::Wrapper listAll(const CheckReportQuery::Wrapper& query);
};

#endif // !_CHECKREPORTLIST_SERVICE_