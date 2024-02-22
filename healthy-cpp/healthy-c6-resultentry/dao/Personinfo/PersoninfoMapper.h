#pragma once
#ifndef _PERSONINFO_MAPPER_
#define _PERSONINFO_MAPPER_

#include "Mapper.h"
#include "../../domain/do/Personinfo/PersoninfoDO.h"

class PersoninfoMapper : public Mapper<PersoninfoDO>
{
public:
	PersoninfoDO mapper(ResultSet* resultSet) const override
	{
		PersoninfoDO data;
		data.setName(resultSet->getString(1));
		data.setAge(resultSet->getInt(2));
		data.setSex(resultSet->getString(3));
		data.setPhysical_type(resultSet->getString(4));
		data.setSporadic_physical(resultSet->getInt(5));
		return data;
	}
};

#endif // !_PERSONINFO_MAPPER_