#pragma once

#ifndef _PERSONINFO_SERVICE_
#define __PERSONINFO_SERVICE_
#include <list>
#include "domain/vo/Personinfo/PersoninfoVO.h"
#include "domain/query/Personinfo/PersoninfoQuery.h"
#include "domain/dto/Personinfo/PersoninfoDTO.h"

class PersoninfoService
{
public:
	// ��ҳ��ѯ��������
	PersoninfoPageDTO::Wrapper listAll(const PersoninfoQuery::Wrapper& query);
};

#endif // !_PERSON_INFOSERVICE_

