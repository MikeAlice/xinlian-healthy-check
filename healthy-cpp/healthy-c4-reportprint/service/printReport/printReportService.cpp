 
#include "stdafx.h"
#include "PrintReportService.h"
#include "../../dao/printreport/PrintReportDAO.h"

bool PrintReportService::updateData(const PrintReportDTO::Wrapper& dto)
{
	// 组装DO数据
	PrintReportDO data;
	data.setId(dto->id.getValue(""));
	data.setReportPrintingNum(dto->report_printing_num.getValue(1));
	data.setPrintState(dto->print_state.getValue(1));

	// 执行数据修改
	PrintReportDAO dao;
	return dao.update(data) == 1;
}


