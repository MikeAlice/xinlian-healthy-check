#pragma once
#ifndef _BASEPROJECT_MAPPER_
#define _BASEPROJECT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/checkitem/BaseProjectDO.h"

class BaseProjectMapper : public Mapper<BaseProjectDO> {
public:
	BaseProjectDO mapper(ResultSet* resultSet) const override
	{
		BaseProjectDO data;
		data.setCode(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setUnit_name(resultSet->getString(3));
		data.setHealthy_value(resultSet->getString(4));
		data.setDefault_value(resultSet->getString(5));
		data.setResult_type(resultSet->getString(6));
		return data;
	}
};

#endif //!_BASEPROJECT_MAPPER_