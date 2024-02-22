#pragma once
#ifndef _PERSONINFO_DAO_
#define _PERSONINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Personinfo/PersoninfoDO.h"
#include "../../domain/query/Personinfo/PersoninfoQuery.h"

class PersoninfoDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const PersoninfoQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<PersoninfoDO> selectWithPage(const PersoninfoQuery::Wrapper& query);
};
#endif // !_PERSONINFO_DAO_
