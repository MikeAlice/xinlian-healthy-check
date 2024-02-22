#pragma once
#ifndef _INTERRO_DAO_
#define _INTERRO_DAO_
#include"BaseDAO.h"
#include"../../domain/do/interro/InterroDO.h"
#include"../../domain/query/interro/InterroQuery.h"

/**
* class InterroDAO
*/
class InterroDAO : public BaseDAO {
public:
	//≤Â»Î ˝æ›
	uint64_t insert(const InterroDO& uObj);
};

#endif // !_INTERRO_DAO_