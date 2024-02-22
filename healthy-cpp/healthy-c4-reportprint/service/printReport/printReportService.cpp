 
#include "stdafx.h"
#include "PrintReportService.h"
#include "../../dao/printreport/PrintReportDAO.h"

bool PrintReportService::updateData(const PrintReportDTO::Wrapper& dto)
{
	// ��װDO����
	PrintReportDO data;
	data.setId(dto->id.getValue(""));
	data.setReportPrintingNum(dto->report_printing_num.getValue(1));
	data.setPrintState(dto->print_state.getValue(1));

	// ִ�������޸�
	PrintReportDAO dao;
	return dao.update(data) == 1;
}


