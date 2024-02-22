#pragma once
#ifndef _PRINT_CONFIRM_MAPPER_
#define _PRINT_CONFIRM_MAPPER_

#include "Mapper.h"
#include "../../domain/do/printconfirm/PrintConfirmDO.h"
class PrintConfirmMapper : public Mapper<PrintConfirmDO>
{
public:
	PrintConfirmDO mapper(ResultSet* resultSet) const override
	{
		PrintConfirmDO data;
		data.setOrderid(resultSet->getString(1));
		return data;
	}
};

#endif // !_PRINT_CONFIRM_MAPPER_