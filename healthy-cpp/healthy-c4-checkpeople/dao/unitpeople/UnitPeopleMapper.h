#pragma once 
#ifndef _UNIT_PEOPLE_MAPPER_
#define _UNIT_PEOPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/unitpeople/UnitPeopleDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class UnitPeopleMapper : public Mapper<UnitPeopleDO>
{
public:
	UnitPeopleDO mapper(ResultSet* resultSet) const override
	{
		UnitPeopleDO data;
		data.setPersonName(resultSet->getString(1));
		data.setSex(resultSet->getString(2));
		data.setIdCard(resultSet->getString(3));
		data.setBirth(resultSet->getString(4));
		data.setAge(resultSet->getInt(5));
		data.setIsMarry(resultSet->getString(6));
		data.setMobile(resultSet->getString(7));
		return data;
	}
};

#endif // !_UNIT_PEOPLE_MAPPER_