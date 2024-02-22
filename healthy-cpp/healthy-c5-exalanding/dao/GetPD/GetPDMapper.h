#pragma once
#ifndef _GETPD_MAPPER_
#define _GETPD_MAPPER_

#include "Mapper.h"
#include "../../domain/do/GetPD/GetPDDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class GetPDMapper : public Mapper<GetPDDO>
{
public:
	GetPDDO mapper(ResultSet* resultSet) const override
	{
		GetPDDO data;
		data.setName(resultSet->getString(1));
		data.setSex(resultSet->getString(2));
		data.setWork_name(resultSet->getString(3));
		data.setId_card(resultSet->getInt(4));
		data.setPhone(resultSet->getInt(5));
		data.setAge(resultSet->getInt(6));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_
