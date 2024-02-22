#pragma once

#ifndef _DOWNLOADREPORT_MAPPER_
#define _DOWNLOADREPORT_MAPPER_

#include "Mapper.h"
#include "../../domain/do/downloadreport/DownloadReportDO.h"

/**
 * ±Ì◊÷∂Œ∆•≈‰”≥…‰
 */
class DownloadReportMapper : public Mapper<DownloadReportDO>
{
public:
	DownloadReportDO mapper(ResultSet* resultSet) const override
	{
		DownloadReportDO data;

		return data;
	}
};

#endif // !_DOWNLOADREPORT_MAPPER_