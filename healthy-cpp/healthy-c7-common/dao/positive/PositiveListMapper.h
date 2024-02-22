#pragma once

#ifndef _POSITIVE_LIST_MAPPER_
#define _POSITIVE_LIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/positive/PositiveListDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class PositiveListMapper : public Mapper<PositiveListDO>
{
public:
	PositiveListDO mapper(ResultSet* resultSet) const override
	{
		PositiveListDO data;
		data.setId(resultSet->getString(1));
		data.setPersonName(resultSet->getString(2));
		data.setTest_Num(resultSet->getString(3));
		data.setOfficeName(resultSet->getString(4));
		data.setOrder_Group_Item_Project_Name(resultSet->getString(5));
		data.setResult(resultSet->getString(6));
		data.setUnit_Name(resultSet->getString(7));
		data.setScope(resultSet->getString(8));
		data.setCrisis_Degree(resultSet->getString(9));
		data.setCheckDate(resultSet->getString(10));
		return data;
	}
};

#endif // !_POSITIVE_LIST_MAPPER_