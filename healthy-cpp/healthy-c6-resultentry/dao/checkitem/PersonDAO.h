#pragma once
#ifndef _PERSON_DAO_
#define _PERSON_DAO_

#include "BaseDAO.h"
#include "../../domain/do/checkitem/PersonDO.h"
#include "../../domain/query/checkitem/PersonQuery.h"

class PersonDAO : public BaseDAO {
public:
	//统计数据条数
	uint64_t count(const PersonQuery::Wrapper& query);
	// 分页查询数据
	list<PersonDO> selectWithPage(const PersonQuery::Wrapper& query);
};

#endif //!_BASEPROJECT_DAO_
