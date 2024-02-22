#pragma once
#ifndef _LIFEHISTORYCONTRONLLER_DAO_
#define _LIFEHISTORYCONTRONLLER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/unknownmodulelifehistory/LifeHistoryDO.h"
#include "../../domain/query/unknownmodulelifehistory/LifeHistoryQuery.h"

class LifeHistoryDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const LifeHistoryQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<LifeHistoryDO> selectWithPage(const LifeHistoryQuery::Wrapper& query);
};
#endif // !_GROUP_PERSON_DAO_
