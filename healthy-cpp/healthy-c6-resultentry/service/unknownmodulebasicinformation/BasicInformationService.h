#pragma once

#ifndef _BASICINFORMATIONCONTROLLER_SERVICE_
#define _BASICINFORMATIONCONTROLLER_SERVICE_
#include <list>
#include "domain/vo/unknownmodulebasicinformation/BasicInformationVO.h"
#include "domain/query/unknownmodulebasicinformation/BasicInformationQuery.h"
#include "domain/dto/unknownmodulebasicinformation/BasicInformationDTO.h"

class BasicInformationService
{
public:
	// ��ѯ��������
	BasicInformationPageDTO::Wrapper listAll(const BasicInformationQuery::Wrapper& query);
};

#endif // !_GROUP_PERSON_SERVICE_

