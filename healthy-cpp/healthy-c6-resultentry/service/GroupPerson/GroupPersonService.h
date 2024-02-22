#pragma once

#ifndef _GROUP_PERSON_SERVICE_
#define _GROUP_PERSON_SERVICE_
#include <list>
#include "domain/vo/GroupPerson/GroupPersonVO.h"
#include "domain/query/GroupPerson/GroupPersonQuery.h"
#include "domain/dto/GroupPerson/GroupPersonDTO.h"

class GroupPersonService
{
public:
	// 分页查询所有数据
	GroupPersonPageDTO::Wrapper listAll(const GroupPersonQuery::Wrapper& query);
};

#endif // !_GROUP_PERSON_SERVICE_

