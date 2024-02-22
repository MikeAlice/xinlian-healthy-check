#include "stdafx.h"
#include "MedExamPrintReportController.h"
#include "../../service/medexamprintreport/MedExamPrintReportService.h"
#include "../ApiDeclarativeServicesHelper.h"

MedExamPrintReportPageJsonVO::Wrapper MedExamPrintReportController::execQueryMedExamPrintReport(const MedExamPrintReportQuery::Wrapper& query)
{

	// ����һ��Service
	MedExamPrintReportService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = MedExamPrintReportPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}