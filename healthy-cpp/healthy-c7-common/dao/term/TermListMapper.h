#pragma once
#ifndef _TERM_MAPPER_
#define _TERM_MAPPER_

#include "Mapper.h"
#include "../../domain/do/term/TermListDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class TermMapper : public Mapper<TermListDO>
{
public:
	TermListDO mapper(ResultSet* resultSet) const override
	{
		TermListDO data;
		data.setId(resultSet->getString(1));
		data.setOfficeId(resultSet->getString(2));
		data.setHazardFactorsText(resultSet->getString(3));
		data.setInspectType(resultSet->getString(4));
		data.setContent(resultSet->getString(5));
		data.setWorkStateText(resultSet->getString(6));
		return data;
	}
};

#endif // !_TERM_MAPPER_