#pragma once

#ifndef _PASTMEDICALHISTORYCONTRONLLER_SERVICE_
#define _PASTMEDICALHISTORYCONTRONLLER_SERVICE_
#include <list>
#include "domain/vo/unknownmodulepastmedicalhistory/PastMedicalHistoryVO.h"
#include "domain/query/unknownmodulepastmedicalhistory/PastMedicalHistoryQuery.h"
#include "domain/dto/unknownmodulepastmedicalhistory/PastMedicalHistoryDTO.h"

class PastMedicalHistoryService
{
public:
	// 查询所有数据
	PastMedicalHistoryPageDTO::Wrapper listAll(const PastMedicalHistoryQuery::Wrapper& query);
};

#endif // !_GROUP_PERSON_SERVICE_

