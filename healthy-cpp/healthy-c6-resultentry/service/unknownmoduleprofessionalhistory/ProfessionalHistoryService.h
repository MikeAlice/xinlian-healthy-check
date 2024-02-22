#pragma once

#ifndef _PROFESSIONALHISTORYCONTRONLLER_SERVICE_
#define _PROFESSIONALHISTORYCONTRONLLER_SERVICE_
#include <list>
#include "domain/vo/unknownmoduleprofessionalhistory/ProfessionalHistoryVO.h"
#include "domain/query/unknownmoduleprofessionalhistory/ProfessionalHistoryQuery.h"
#include "domain/dto/unknownmoduleprofessionalhistory/ProfessionalHistoryDTO.h"

class ProfessionalHistoryService
{
public:
	// 查询所有数据
	ProfessionalHistoryPageDTO::Wrapper listAll(const ProfessionalHistoryQuery::Wrapper& query);
};

#endif // !_GROUP_PERSON_SERVICE_

