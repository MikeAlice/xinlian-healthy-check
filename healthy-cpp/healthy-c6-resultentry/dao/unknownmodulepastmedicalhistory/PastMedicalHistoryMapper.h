#pragma once
#ifndef _PASTMEDICALHISTORYCONTRONLLER_MAPPER_
#define _PASTMEDICALHISTORYCONTRONLLER_MAPPER_

#include "Mapper.h"
#include "../../domain/do/unknownmodulepastmedicalhistory/PastMedicalHistoryDO.h"

class PastMedicalHistoryMapper : public Mapper<PastMedicalHistoryDO>
{
public:
	PastMedicalHistoryDO mapper(ResultSet* resultSet) const override
	{
		PastMedicalHistoryDO data;
		data.setPerson_id(resultSet->getString(1));
		data.setAbortion(resultSet->getInt(2));
		data.setPremature(resultSet->getInt(3));
		data.setDeath(resultSet->getInt(4));
		data.setAbnormal_fetus(resultSet->getInt(5));
		data.setMenstrual_history(resultSet->getString(6));
		data.setMenstrual_info(resultSet->getString(7));
		data.setAllergies(resultSet->getString(8));
		data.setAllergies_info(resultSet->getString(9));
		data.setPast_medical_history(resultSet->getString(10));
		data.setPast_medical_history_other_info(resultSet->getString(11));
		return data;
	}
};

#endif // !_GROUP_PERSON_MAPPER_