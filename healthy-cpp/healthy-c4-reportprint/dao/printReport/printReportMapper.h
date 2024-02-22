#pragma once

#ifndef _PRINTREPORT_MAPPER_
#define _PRINTREPORT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/printreport/PrintReportDO.h"

/**
 * ±Ì◊÷∂Œ∆•≈‰”≥…‰
 */
class PrintReportMapper : public printReport<PrintReportDO>
{
public:
	PrintReportDO mapper(ResultSet* resultSet) const override
	{
		PrintReportDO data;
		data.setId(resultSet->getString(1));
		data.setReportPrintingNum(resultSet->getUInt32(2));
		data.setPrintState(resultSet->getUInt32(3));
		return data;
	}
};

#endif // !_PRINTREPORT_MAPPER_