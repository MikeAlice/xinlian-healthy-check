#pragma once
#ifndef _ADDNEWITEMS_MAPPER_
#define _ADDNEWITEMS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/addNewItems/AddNewItemsDO.h"

/**
 * 复查记录表字段匹配映射
 */
class AddNewItemsMapper : public Mapper<AddNewItemsDO>
{
public:
	AddNewItemsDO mapper(ResultSet* resultSet) const override
	{
		AddNewItemsDO data;
		data.setCheckProjectId(resultSet->getString(1)); // 1指查询结果的第一列
		data.setCheckProjectName(resultSet->getString(2));
		data.setPortfolioProjectId(resultSet->getString(3));
		data.setPortfolioProjectName(resultSet->getString(4));
		data.setReason(resultSet->getString(5));
		return data;
	}
};

#endif // !_ADDNEWITEMS_MAPPER_