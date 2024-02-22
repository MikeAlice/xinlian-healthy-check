#pragma once

#ifndef _JOINPERSONLIST_MAPPER_
#define _JOINPERSONLIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/personlist/JoinPersonListDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class JoinPersonListMapper : public Mapper<JoinPersonListDO>
{
public:
	JoinPersonListDO mapper(ResultSet* resultSet) const override
	{
		JoinPersonListDO data;
		data.setTestNum(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setIdCard(resultSet->getUInt64(3));
		data.setHazardFactor(resultSet->getString(4));
		data.setCheckDate(resultSet->getUInt64(5));
		data.setComments(resultSet->getString(6));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_