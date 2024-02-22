#pragma once
#ifndef _RULESLIST_MAPPER_
#define _RULESLIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/rules/RulesListDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class RulesListMapper : public Mapper<RulesListDO>
{
public:
	RulesListDO mapper(ResultSet* resultSet) const override
	{
		RulesListDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		data.setShort_name(resultSet->getString(3));
		data.setType(resultSet->getString(4));
		data.setInterval_value(resultSet->getString(5));
		data.setAllow_Sex(resultSet->getString(6));
		data.setMin_Age(resultSet->getUInt64(7));
		data.setMax_Age(resultSet->getUInt64(8));
		data.setIn_conclusion(resultSet->getString(9));
		data.setPositive(resultSet->getString(10));
		data.setCaree_advice(resultSet->getString(11));
		data.setHealth_advice(resultSet->getString(12));
		data.setDietary_guidance(resultSet->getString(13));
		data.setSports_guidance(resultSet->getString(14));
		data.setHealth_knowledge(resultSet->getString(15));
		data.setReminder(resultSet->getString(16));
		data.setDepartment_id(resultSet->getString(17));
		data.setBase_project_id(resultSet->getString(18));
		data.setCreate_id(resultSet->getString(19));
		data.setCreate_time(resultSet->getString(20));
		
		return data;
	}
};

#endif // !_RULESLIST_MAPPER_