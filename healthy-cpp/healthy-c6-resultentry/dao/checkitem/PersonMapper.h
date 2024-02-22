#pragma once
#ifndef _PERSON_MAPPER_
#define _PERSON_MAPPER_

#include "Mapper.h"
#include "../../domain/do/checkitem/PersonDO.h"

class PersonMapper : public Mapper<PersonDO> {
public:
	PersonDO mapper(ResultSet* resultSet) const override
	{
		PersonDO data;
		data.setId(resultSet->getString(1));
		data.setPortfolioName(resultSet->getString(2));
		return data;
	}
};

#endif //!_PERSON_MAPPER_