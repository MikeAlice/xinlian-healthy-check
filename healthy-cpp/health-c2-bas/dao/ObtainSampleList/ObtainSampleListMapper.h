#pragma once
#ifndef _OBTAINSAMPLELIST_MAPPER_
#define _OBTAINSAMPLELIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/sample/ObtainSampleListDO.h"

/**
 * 字段匹配映射
 */
class ObtainSampleListMapper : public Mapper<ObtainSampleListDO>
{
public:
	ObtainSampleListDO mapper(ResultSet* resultSet) const override
	{
		ObtainSampleListDO data;
		data.setName(resultSet->getString(1));
		data.setCode(resultSet->getString(2));
		data.setLiscode(resultSet->getString(3));
		return data;
	}
};

#endif // !_OBTAINSAMPLELIST_MAPPER_