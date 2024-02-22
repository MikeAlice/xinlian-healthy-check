#pragma once
#ifndef _REPORTLIST_DAO_
#define _REPORTLIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/reportlist/ReportListDO.h"
#include "../../domain/query/reportlist/ReportListQuery.h"

/**
 * 示例表数据库操作实现
 */
class ReportListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ReportListQuery::Wrapper& query);
	// 分页查询数据
	list<ReportListDO> selectWithPage(const ReportListQuery::Wrapper& query);
};
#endif // !_REPORTLIST_DAO_
