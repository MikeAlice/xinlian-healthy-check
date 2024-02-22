#pragma once
#ifndef _PROFESSIONALHISTORYCONTRONLLER_DAO_
#define _PROFESSIONALHISTORYCONTRONLLER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/unknownmoduleprofessionalhistory/ProfessionalHistoryDO.h"
#include "../../domain/query/unknownmoduleprofessionalhistory/ProfessionalHistoryQuery.h"

class ProfessionalHistoryDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const ProfessionalHistoryQuery::Wrapper& query);
	// 分页查询数据
	list<ProfessionalHistoryDO> selectWithPage(const ProfessionalHistoryQuery::Wrapper& query);
};
#endif // !_GROUP_PERSON_DAO_
