#pragma once
#ifndef _BASEPROJECT_DAO_
#define _BASEPROJECT_DAO_

#include "BaseDAO.h"
#include "../../domain/do/checkitem/BaseProjectDO.h"
#include "../../domain/query/checkitem/BaseProjectQuery.h"

class BaseProjectDAO : public BaseDAO {
public:
	//统计数据条数
	uint64_t count(const BaseProjectQuery::Wrapper& query);
	// 分页查询数据
	list<BaseProjectDO> selectWithPage(const BaseProjectQuery::Wrapper& query);
};

#endif //!_BASEPROJECT_DAO_
