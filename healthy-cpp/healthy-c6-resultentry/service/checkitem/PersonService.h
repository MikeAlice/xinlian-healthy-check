#pragma once
#ifndef _PERSON_SERVICE_
#define _PERSON_SERVICE_

#include <list>
#include "domain/vo/checkitem/PersonVO.h"
#include "domain/query/checkitem/PersonQuery.h"
#include "domain/dto/checkitem/PersonDTO.h"

class PersonService {
public:
	// 分页查询所有数据
	PersonPageDTO::Wrapper listAll(const PersonQuery::Wrapper& query);
};


#endif