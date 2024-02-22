#include "stdafx.h"
#include "MedExamPrintReportController.h"
#include "../../service/medexamprintreport/MedExamPrintReportService.h"
#include "../ApiDeclarativeServicesHelper.h"

MedExamPrintReportPageJsonVO::Wrapper MedExamPrintReportController::execQueryMedExamPrintReport(const MedExamPrintReportQuery::Wrapper& query)
{

	// 定义一个Service
	MedExamPrintReportService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = MedExamPrintReportPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}