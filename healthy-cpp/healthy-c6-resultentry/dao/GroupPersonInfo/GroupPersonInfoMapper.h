#pragma once
#ifndef _GROUP_PERSON_INFO_MAPPER_
#define _GROUP_PERSON_INFO_MAPPER_

#include "Mapper.h"
#include "../../domain/do/GroupPersonInfo/GroupPersonInfoDO.h"

class GroupPersonInfoMapper : public Mapper<GroupPersonInfoDO>
{
public:
	GroupPersonInfoDO mapper(ResultSet* resultSet) const override
	{
		GroupPersonInfoDO data;
		data.setIs_pass(resultSet->getInt(1));
		data.setTest_num(resultSet->getString(2));
		data.setId_card(resultSet->getString(3));
		data.setPerson_name(resultSet->getString(4));
		data.setSex(resultSet->getString(5));
		data.setAge(resultSet->getInt(6));
		data.setPhysical_type(resultSet->getString(7));
		data.setSporadic_physical(resultSet->getInt(8));
		data.setDept(resultSet->getString(9));
		data.setCreate_time(resultSet->getString(10));
		return data;
	}
};

#endif // !_GROUP_PERSON_INFO_MAPPER_