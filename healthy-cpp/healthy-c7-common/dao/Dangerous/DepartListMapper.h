#pragma once
#ifndef _DEPART_LIST_MAPPER_
#define _DEPART_LIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Dangerous/DepartListDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class DepartListMapper : public Mapper<DepartListDO>
{
public:
	DepartListDO mapper(ResultSet* resultSet) const override
	{
		DepartListDO data;
		data.setOfficeName(resultSet->getString(1));
		data.setProjectName(resultSet->getString(2));
		data.setResult(resultSet->getString(3));
		data.setScope(resultSet->getString(4));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_