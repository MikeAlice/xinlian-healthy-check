#pragma once
#ifndef _PERSONINFO_DAO_
#define _PERSONINFO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/Personinfo/PersoninfoDO.h"
#include "../../domain/query/Personinfo/PersoninfoQuery.h"

class PersoninfoDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const PersoninfoQuery::Wrapper& query);
	// 分页查询数据
	list<PersoninfoDO> selectWithPage(const PersoninfoQuery::Wrapper& query);
};
#endif // !_PERSONINFO_DAO_
