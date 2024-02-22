#pragma once
#ifndef _CHECKREPORTLIST_DAO_
#define _CHECKREPORTLIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/checks/CheckReportListDO.h"
#include "../../domain/query/checks/CheckReportQuery.h"

/**
 * 报告审核获取列表数据库操作实现
 * 负责人 Z
 */
class CheckReportListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const CheckReportQuery::Wrapper& query);
	// 分页查询数据
	list<CheckReportListDO> selectWithPage(const CheckReportQuery::Wrapper& query);
};
#endif // !_CHECKREPORTLIST_DAO_
