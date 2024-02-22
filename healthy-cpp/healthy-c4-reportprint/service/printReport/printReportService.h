#pragma once
 
#ifndef _PRINTREPORT_SERVICE_
#define _PRINTREPORT_SERVICE_
#include <list>
#include "domain/vo/printreport/PrintReportVO.h"
#include "domain/query/printreport/PrintReportQuery.h"
#include "domain/dto/printreport/PrintReportDTO.h"

class PrintReportService
{
public:
	bool updateData(const PrintReportDTO::Wrapper& dto);
};

#endif // !_PRINTREPORT_SERVICE_

