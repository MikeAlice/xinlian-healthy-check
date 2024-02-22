#pragma once
#ifndef _GROUP_PERSON_INFO_SERVICE_
#define _GROUP_PERSON_INFO_SERVICE_
#include <list>
#include "domain/vo/GroupPersonInfo/GroupPersonInfoVO.h"
#include "domain/query/GroupPersonInfo/GroupPersonInfoQuery.h"
#include "domain/dto/GroupPersonInfo/GroupPersonInfoDTO.h"

class GroupPersonInfoService
{
public:
	// ²éÑ¯Êý¾Ý
	GroupPersonInfoDTO::Wrapper queryInfo(const GroupPersonInfoQuery::Wrapper& query);
};

#endif // !_GROUP_PERSON_INFO_SERVICE_

