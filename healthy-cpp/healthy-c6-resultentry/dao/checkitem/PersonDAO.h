#pragma once
#ifndef _PERSON_DAO_
#define _PERSON_DAO_

#include "BaseDAO.h"
#include "../../domain/do/checkitem/PersonDO.h"
#include "../../domain/query/checkitem/PersonQuery.h"

class PersonDAO : public BaseDAO {
public:
	//ͳ����������
	uint64_t count(const PersonQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<PersonDO> selectWithPage(const PersonQuery::Wrapper& query);
};

#endif //!_BASEPROJECT_DAO_
