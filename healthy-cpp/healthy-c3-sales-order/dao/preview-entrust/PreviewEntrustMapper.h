#pragma once

#ifndef _PREVIEWENTRUSTMAPPER_H_
#define _PREVIEWENTRUSTMAPPER_H_

#include "Mapper.h"
#include "../../domain/do/preview-entrust/PreviewEntrustDO.h"
#include <string>

class MapperUrl : public Mapper<PreviewEntrustUrlDO>
{
public:
	PreviewEntrustUrlDO mapper(ResultSet* resultSet) const override
	{
		PreviewEntrustUrlDO data;
		data.setOrderPath(resultSet->getString(1));
		return data;
	}
};

class MapperInfo : public Mapper<PreviewEntrustInfoDO>
{
public:
	PreviewEntrustInfoDO mapper(ResultSet* resultSet) const override
	{
		PreviewEntrustInfoDO data;
		data.setOrderCode(resultSet->getString(1));
		data.setGroupUnitName(resultSet->getString(2));
		data.setLinkMan2(resultSet->getString(3));
		data.setLinkPhone2(resultSet->getString(4));
		data.setStartDate(resultSet->getString(5));
		data.setEndDate(resultSet->getString(6));
		return data;
	}
};
#endif // !_PREVIEWENTRUSTMAPPER_H_