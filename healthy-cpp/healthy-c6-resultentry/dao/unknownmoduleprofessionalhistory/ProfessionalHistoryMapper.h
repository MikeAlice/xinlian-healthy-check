#pragma once
#ifndef _PROFESSIONALHISTORYCONTRONLLER_MAPPER_
#define _PROFESSIONALHISTORYCONTRONLLER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/unknownmoduleprofessionalhistory/ProfessionalHistoryDO.h"

class ProfessionalHistoryMapper : public Mapper<ProfessionalHistoryDO>
{
public:
	ProfessionalHistoryDO mapper(ResultSet* resultSet) const override
	{
		ProfessionalHistoryDO data;
		data.setPerson_id(resultSet->getString(1));
		data.setStart_date(resultSet->getString(2));
		data.setEnd_date(resultSet->getString(3));
		data.setWork_unit(resultSet->getString(4));
		data.setDepartment(resultSet->getString(5));
		data.setWork_type_text(resultSet->getString(6));
		data.setHazard_factors_text(resultSet->getString(7));
		data.setProtective_measures(resultSet->getString(8));
		data.setContact_time(resultSet->getString(9));
		return data;
	}
};

#endif // !_GROUP_PERSON_MAPPER_