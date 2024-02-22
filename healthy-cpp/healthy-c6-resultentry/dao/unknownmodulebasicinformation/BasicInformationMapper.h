#pragma once
#ifndef _BASICINFORMATIONCONTROLLER_MAPPER_
#define _BASICINFORMATIONCONTROLLER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/unknownmodulebasicinformation/BasicInformationDO.h"

class BasicInformationMapper : public Mapper<BasicInformationDO>
{
public:
	BasicInformationDO mapper(ResultSet* resultSet) const override
	{
		BasicInformationDO data;
		data.setPerson_id(resultSet->getString(1));
		data.setJob(resultSet->getString(2));
		data.setWork_year(resultSet->getInt(3));
		data.setWork_month(resultSet->getInt(4));
		data.setExposure_start_date(resultSet->getString(5));
		data.setEducation(resultSet->getString(6));
		data.setFamily_address(resultSet->getString(7));
		data.setMarriage_date(resultSet->getString(8));
		return data;
	}
};

#endif // !_GROUP_PERSON_MAPPER_