#pragma once
#ifndef _GROUP_PERSON_MAPPER_
#define _GROUP_PERSON_MAPPER_

#include "Mapper.h"
#include "../../domain/do/GroupPerson/GroupPersonDO.h"

class GroupPersonMapper : public Mapper<GroupPersonDO>
{
public:
	GroupPersonDO mapper(ResultSet* resultSet) const override
	{
		GroupPersonDO data;
		data.setName(resultSet->getString(1));
		data.setSex(resultSet->getString(2));
		data.setAge(resultSet->getInt(3));
		data.setPhysical_type(resultSet->getString(4));
		data.setSporadic_physical(resultSet->getInt(5));
		return data;
	}
};

#endif // !_GROUP_PERSON_MAPPER_