#pragma once
#ifndef _COUNTCHECK_DAO_
#define _COUNTCHECK_DAO_
#include "BaseDAO.h"
#include "../../domain/query/check/CountCheckQuery.h"

/**
 * 示例表数据库操作实现
 */
class CountCheckDAO : public BaseDAO
{
public:
	//统计审核完成的合同
	uint64_t count(const CountCheckQuery::Wrapper& query);

	//统计未审核完成的合同
	uint64_t count2(const CountCheckQuery::Wrapper& query);

};
#endif // !_COUNTCHECK_DAO_
