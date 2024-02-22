#pragma once
#ifndef _NAMELIST_DAO_
#define _NAMELIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/contract/NameListDO.h"
#include "../../domain/query/contract/NameListQuery.h"

/**
 * 示例表数据库操作实现
 */
class NameListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const NameListQuery::Wrapper& query);
	// 分页查询数据
	list<NameListDO> selectWithPage(const NameListQuery::Wrapper& query);

};
#endif // !_SAMPLE_DAO_