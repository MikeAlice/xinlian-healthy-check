#pragma once

#ifndef _PRINTREPORT_DAO_
#define _PRINTREPORT_DAO_
#include "BaseDAO.h"
#include "../../domain/do/printreport/PrintReportDO.h"
#include "../../domain/query/printreport/PrintReportQuery.h"

/**
 * 示例表数据库操作实现
 */
class PrintReportDAO : public BaseDAO
{
public:
	// 修改数据
	int update(const PrintReportDO& uObj);
};


#endif // !_PRINTREPORT_DAO_
