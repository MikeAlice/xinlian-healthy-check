#pragma once
#ifndef _NAMELIST_MAPPER_
#define _NAMELIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/contract/NameListDO.h"

/**
 * 名称列表表字段匹配映射
 */
class NameListMapper : public Mapper<NameListDO>
{
public:
	NameListDO mapper(ResultSet* resultSet) const override
	{
		NameListDO data;
		data.setSigningTime(resultSet->getString(1));
		data.setGroupUnitName(resultSet->getString(2));
		data.setAuditState(resultSet->getUInt(3));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_