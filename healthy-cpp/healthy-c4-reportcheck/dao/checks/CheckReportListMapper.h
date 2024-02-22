#pragma once
#ifndef _CHECKREPORTLIST_MAPPER_
#define _CHECKREPORTLIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/checks/CheckReportListDO.h"

/**
 * 查询列表表字段匹配映射
 * 负责人Z
 */
class CheckReportListMapper : public Mapper<CheckReportListDO>
{
public:
	CheckReportListDO mapper(ResultSet* resultSet) const override
	{
		CheckReportListDO data;
		data.setId(resultSet->getString(1));
		data.setPerson_name(resultSet->getString(2));
		data.setSex(resultSet->getString(3));
		data.setAge(resultSet->getInt(4));
		data.setStatu(resultSet->getBoolean(5));
		data.setPrint_state(resultSet->getBoolean(6));
		data.setSporadic_physical(resultSet->getBoolean(7));
		return data;
	}
};

#endif // !_CHECKREPORTLIST_MAPPER_