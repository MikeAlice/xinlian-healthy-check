#pragma once

#ifndef _DELETE_SAMPLE_DAO_
#define _DELETE_SAMPLE_DAO_
#include "Mapper.h"
#include "../../domain/do/sample/DeleteSampleDO.h"

/**
 * Ê¾Àý±í×Ö¶ÎÆ¥ÅäÓ³Éä
 */
class SampleMapper : public Mapper<DeleteSampleDO>
{
public:
	DeleteSampleDO mapper(ResultSet* resultSet) const override
	{
		DeleteSampleDO data;
		data.setDel_flag(resultSet->getUInt64(1));
		data.setCreate_id(resultSet->getUInt64(2));
		data.setCreate_time(resultSet->getString(3));
		data.setUpdate_id(resultSet->getUInt64(4));
		data.setUpdate_time(resultSet->getString(5));
		data.setDelete_id(resultSet->getUInt64(6));
		data.setDelete_time(resultSet->getString(7));
		data.setDepartment_id(resultSet->getUInt64(8));
		return data;
	}
};

#endif // 