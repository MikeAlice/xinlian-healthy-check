#pragma once

#ifndef _LIFEHISTORYCONTRONLLER_SERVICE_
#define _LIFEHISTORYCONTRONLLER_SERVICE_
#include <list>
#include "domain/vo/unknownmodulelifehistory/LifeHistoryVO.h"
#include "domain/query/unknownmodulelifehistory/LifeHistoryQuery.h"
#include "domain/dto/unknownmodulelifehistory/LifeHistoryDTO.h"

class LifeHistoryService
{
public:
	// 查询所有数据
	LifeHistoryPageDTO::Wrapper listAll(const LifeHistoryQuery::Wrapper& query);
};

#endif // !_GROUP_PERSON_SERVICE_

