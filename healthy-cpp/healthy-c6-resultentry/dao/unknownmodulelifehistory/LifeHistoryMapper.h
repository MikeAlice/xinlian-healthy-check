#pragma once
#ifndef _LIFEHISTORYCONTRONLLER_MAPPER_
#define _LIFEHISTORYCONTRONLLER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/unknownmodulelifehistory/LifeHistoryDO.h"

class LifeHistoryMapper : public Mapper<LifeHistoryDO>
{
public:
	LifeHistoryDO mapper(ResultSet* resultSet) const override
	{
		LifeHistoryDO data;
		data.setPerson_id(resultSet->getString(1));
		data.setExisting_children(resultSet->getInt(2));
		data.setAllergies(resultSet->getString(3));
		data.setSmoke_state(resultSet->getString(4));
		data.setPackage_every_day(resultSet->getInt(5));
		data.setSmoke_year(resultSet->getInt(6));
		data.setDrink_state(resultSet->getString(7));
		data.setMl_every_day(resultSet->getInt(8));
		data.setDrink_year(resultSet->getInt(9));
		data.setBirthplace_name(resultSet->getString(10));
		data.setFamily_history(resultSet->getString(11));
		return data;
	}
};

#endif // !_GROUP_PERSON_MAPPER_