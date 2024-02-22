#pragma once

#ifndef _SELECTBASEPROJECT_MAPPER_H_
#define _SELECTBASEPROJECT_MAPPER_H_

#include "Mapper.h"
#include "../../../domain/do/baseproject/SelectBaseProjectDO.h"

class SelectBaseProjectMapper : public Mapper<SelectBaseProjectDO>
{
public:
    SelectBaseProjectDO mapper(ResultSet* resultSet) const override
    {
        SelectBaseProjectDO data;
        data.setId(resultSet->getString(1));
        data.setCode(resultSet->getString(2));
        data.setName(resultSet->getString(3));
        data.setShortName(resultSet->getString(4));
        data.setOrderNum(resultSet->getDouble(5));
        data.setOfficeId(resultSet->getString(6));
        data.setOfficeName(resultSet->getString(7));
        data.setUnitCode(resultSet->getString(8));
        data.setUnitName(resultSet->getString(9));
        data.setDefaultValue(resultSet->getString(10));
        data.setResultType(resultSet->getString(11));
        data.setInConclusion(resultSet->getString(12));
        data.setInReport(resultSet->getString(13));
        data.setRelationCode(resultSet->getString(14));
        data.setDelFlag(resultSet->getUInt(15));
        data.setCreateId(resultSet->getString(16));
        data.setCreateTime(resultSet->getString(17));
        data.setUpdateId(resultSet->getString(18));
        data.setUpdateTime(resultSet->getString(19));
        data.setDeleteId(resultSet->getString(20));
        data.setDeleteTime(resultSet->getString(21));
        data.setDepartmentId(resultSet->getString(22));
        return data;
    }
};



#endif // !_SELECTBASEPROJECT_MAPPER_H_