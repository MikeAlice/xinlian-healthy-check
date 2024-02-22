
#pragma once
#ifndef _INSERTSAMPLE_MAPPER_
#define _INSERTSAMPLE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/sample/InsertSampleDO.h"



class InsertSampleMapper : public Mapper<InsertSampleDO>
{
public:
	InsertSampleDO mapper(ResultSet* resultSet) const override
	{
		InsertSampleDO data;
		data.setName(resultSet->getString(1));
		data.setSpec(resultSet->getString(2));
		data.setCode(resultSet->getString(3));
		data.setIs_print(resultSet->getUInt(4));
		data.setCapacity(resultSet->getString(5));
		data.setBarcode_num(resultSet->getUInt(6));
		data.setNeed_take_blood(resultSet->getUInt(7));
		data.setOrder_num(resultSet->getDouble(8));
		data.setLiscode(resultSet->getString(9));
		data.setDel_flag(resultSet->getUInt(10));
		return data;
	}
};

#endif // !_INSERTSAMPLE_MAPPER_

