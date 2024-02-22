#pragma once
#ifndef _UNITPHYSICALEXAMINATIONORDERS_MAPPER_
#define _UNITPHYSICALEXAMINATIONORDERS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/unitreportlist/UnitPhysicalExaminationOrdersDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class UnitPhysicalExaminationOrdersMapper : public Mapper<UnitPhysicalExaminationOrdersDO>
{
public:
	UnitPhysicalExaminationOrdersDO mapper(ResultSet* resultSet) const override
	{
		UnitPhysicalExaminationOrdersDO data;
		data.setName(resultSet->getString(1));
		data.setCode(resultSet->getString(2));
		data.setSigningTime(resultSet->getString(3));
		data.setEscalation(resultSet->getInt(4));
		data.setDetectionType(resultSet->getInt(5));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_