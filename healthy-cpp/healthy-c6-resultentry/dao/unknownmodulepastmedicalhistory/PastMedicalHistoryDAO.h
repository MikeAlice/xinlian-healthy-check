#pragma once
#ifndef _PASTMEDICALHISTORYCONTRONLLER_DAO_
#define _PASTMEDICALHISTORYCONTRONLLER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/unknownmodulepastmedicalhistory/PastMedicalHistoryDO.h"
#include "../../domain/query/unknownmodulepastmedicalhistory/PastMedicalHistoryQuery.h"

class PastMedicalHistoryDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const PastMedicalHistoryQuery::Wrapper& query);
	// 分页查询数据
	list<PastMedicalHistoryDO> selectWithPage(const PastMedicalHistoryQuery::Wrapper& query);
};
#endif // !_GROUP_PERSON_DAO_
