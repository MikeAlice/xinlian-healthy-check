#pragma once
#ifndef _PASTMEDICALHISTORYCONTRONLLER_DAO_
#define _PASTMEDICALHISTORYCONTRONLLER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/unknownmodulepastmedicalhistory/PastMedicalHistoryDO.h"
#include "../../domain/query/unknownmodulepastmedicalhistory/PastMedicalHistoryQuery.h"

class PastMedicalHistoryDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const PastMedicalHistoryQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<PastMedicalHistoryDO> selectWithPage(const PastMedicalHistoryQuery::Wrapper& query);
};
#endif // !_GROUP_PERSON_DAO_
