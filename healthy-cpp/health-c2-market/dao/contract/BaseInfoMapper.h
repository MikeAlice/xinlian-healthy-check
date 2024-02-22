#pragma once
#ifndef _BSAEINFO_MAPPER_
#define _BSAEINFO_MAPPER_

#include "Mapper.h"
#include "../../domain/do/contract/BaseInfoDO.h"

/**
 * 名称列表表字段匹配映射
 */
class BaseInfoMapper : public Mapper<BaseInfoDO>
{
public:
	BaseInfoDO mapper(ResultSet* resultSet) const override
	{
		BaseInfoDO data;
		data.setOrderName(resultSet->getString(1));
		data.setOrderId(resultSet->getString(2));
		data.setGroupUnitName(resultSet->getString(3));
		data.setPhysicalType(resultSet->getString(4));
		data.setDeptName(resultSet->getString(5));
		data.setCreateId(resultSet->getString(6));
		data.setAuditUserName(resultSet->getString(7));
		data.setAuditState(resultSet->getString(8));
		data.setPersonName(resultSet->getString(9));
		data.setMobile(resultSet->getString(10));
		data.setAuditTime(resultSet->getString(11));
		data.setSalesDirectorName(resultSet->getString(12));
		data.setSigningTime(resultSet->getString(13));
		data.setDTime(resultSet->getString(14));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_