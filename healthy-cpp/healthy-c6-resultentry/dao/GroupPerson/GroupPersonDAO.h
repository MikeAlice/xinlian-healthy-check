#pragma once
#ifndef _GROUP_PERSON_DAO_
#define _GROUP_PERSON_DAO_
#include "BaseDAO.h"
#include "../../domain/do/GroupPerson/GroupPersonDO.h"
#include "../../domain/query/GroupPerson/GroupPersonQuery.h"

class GroupPersonDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const GroupPersonQuery::Wrapper& query);
	// 分页查询数据
	list<GroupPersonDO> selectWithPage(const GroupPersonQuery::Wrapper& query);
};
#endif // !_GROUP_PERSON_DAO_
