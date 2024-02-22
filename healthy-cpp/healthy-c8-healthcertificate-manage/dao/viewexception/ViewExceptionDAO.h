#pragma once
#ifndef _VIEW_EXCEPTION_DAO_
#define _VIEW_EXCEPTION_DAO_
#include "BaseDAO.h"
#include "../../domain/do/viewexception/ViewExceptionDO.h"
#include "../../domain/query/viewexception/ViewExceptionQuery.h"

/**
 * 示例表数据库操作实现
 */
class ViewExceptionDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ViewExceptionQuery::Wrapper& query);
	// 查询数据
	list<ViewExceptionDO> selectByID(const ViewExceptionQuery::Wrapper& query);
};
#endif // !_VIEW_EXCEPTION_DAO_
