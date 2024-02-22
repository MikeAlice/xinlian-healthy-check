#pragma once
#ifndef _BASEPROJECT_SERVICE_
#define _BASEPROEJCT_SERVICE_

#include <list>
#include "domain/vo/checkitem/BaseProjectVO.h"
#include "domain/query/checkitem/BaseProjectQuery.h"
#include "domain/dto/checkitem/BaseProjectListDTO.h"

class BaseProjectService {
public:
	// ��ҳ��ѯ��������
	BaseProjectPageDTO::Wrapper listAll(const BaseProjectQuery::Wrapper& query);
};


#endif