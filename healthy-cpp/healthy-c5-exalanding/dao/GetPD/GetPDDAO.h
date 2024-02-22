#pragma once
#ifndef _GETPD_DAO_
#define _GETPD_DAO_
#include "BaseDAO.h"
#include "../../domain/do/GetPD/GetPDDO.h"
#include "../../domain/query/GetPD/GetPDQuery.h"

/**
 * 示例表数据库操作实现
 */
class GetPDDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const GetPDQuery::Wrapper& query);
	// 分页查询数据
	list<GetPDDO> selectWithPage(const GetPDQuery::Wrapper& query);
};
#endif // !_GETPD_DAO_