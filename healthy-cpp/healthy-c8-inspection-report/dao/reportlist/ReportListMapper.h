#pragma once
#ifndef _REPORTLIST_MAPPER_
#define _REPORTLIST_MAPPER_

#include "Mapper.h"
#include "../../domain/do/reportlist/ReportListDO.h"

class ReportListMapper : public Mapper<ReportListDO>
{
public:
	ReportListDO mapper(ResultSet* resultSet) const override
	{
		ReportListDO data;
		data.setTest_num(resultSet->getString(1));
		data.setId_card(resultSet->getString(2));
		data.setPerson_name(resultSet->getString(3));
		data.setSex(resultSet->getString(4));
		data.setAge(resultSet->getInt(5));
		data.setCheck_date(resultSet->getString(6));
		data.setCheck_result(resultSet->getString(7));
		data.setPhysical_unit(resultSet->getString(8));
		data.setStatu(resultSet->getInt(9));
		return data;
	}
};

#endif // !_REPORTLIST_MAPPER_