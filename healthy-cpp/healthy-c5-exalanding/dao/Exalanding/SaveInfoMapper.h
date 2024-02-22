#pragma once
#ifndef _SAVE_INFO_MAPPER_
#define _SAVE_INFO_MAPPER_
#include "Mapper.h"
#include "../../domain/do/Exalanding/SaveInfoDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class SaveInfoMapper : public Mapper<SaveInfoDO>
{
public:
	SaveInfoDO mapper(ResultSet* resultSet) const override
	{
		SaveInfoDO data;
		data.setId_card(resultSet->getString(1));
		data.setPerson_name(resultSet->getString(2));
		data.setSex(resultSet->getString(3));
		data.setAge(resultSet->getInt(4));
		data.setMobile(resultSet->getString(5));
		data.setIs_marry(resultSet->getString(6));
		data.setId(resultSet->getString(7));
		data.setIs_pass(resultSet->getInt(8));
		data.setPhysical_type(resultSet->getString(9));
		return data;
	}
};

#endif // !_SAVE_INFO_MAPPER_