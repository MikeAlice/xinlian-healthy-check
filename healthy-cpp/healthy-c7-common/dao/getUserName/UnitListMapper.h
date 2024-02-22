#pragma once

#ifndef _UnitList_MAPPER_
#define _UnitList_MAPPER_

#include "Mapper.h"
#include "../../domain/do/getUserName/UnitListDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class UnitListMapper : public Mapper<UnitListDO>
{
public:
	UnitListDO mapper(ResultSet* resultSet) const override
	{
		UnitListDO data;
		data.setPersonName(resultSet->getString(1));
		data.setSex(resultSet->getString(2));
		data.setAge(resultSet->getInt(3));
		data.setPhysicalType(resultSet->getString(4));
		data.setSporadicPhysical(resultSet->getInt(5));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_