#pragma once
#ifndef _BASEINFO_DAO_
#define _BASEINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/contract/BaseInfoDO.h"
#include "../../domain/query/contract/BaseInfoQuery.h"

/**
 * 示例表数据库操作实现
 */
class BaseInfoDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const BaseInfoQuery::Wrapper& query);
	// 分页查询数据
	list<BaseInfoDO> selectWithPage(const BaseInfoQuery::Wrapper& query);

};
#endif // !_SAMPLE_DAO_