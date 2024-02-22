#pragma once



#ifndef _PRINTREPORT_DO_
#define _PRINTREPORT_DO_
#include "../DoInclude.h"

class PrintReportDO
{
	// id
	CC_SYNTHESIZE(string, id, Id);
	// 打印次数
	CC_SYNTHESIZE(int, report_printing_num, ReportPrintingNum);
	// 打印状态
	CC_SYNTHESIZE(int, print_state, PrintState);
public:
	PrintReportDO() {
		id = "";
		report_printing_num = 0;
		print_state = 0;
	}
};

#endif // !_PRINTREPORT_DO_
