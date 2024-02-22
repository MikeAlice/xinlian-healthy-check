#pragma once

#ifndef _STATISTICALMESSAGE_MAPPER_
#define _STATISTICALMESSAGE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/statisticalmessage/StatisticalMessageDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class StatisticalMessageMapper : public Mapper< StatisticalMessageDO>
{
public:
	StatisticalMessageDO mapper(ResultSet* resultSet) const override
	{
		StatisticalMessageDO data;
		data.setIsPass(resultSet->getUInt64(1));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_