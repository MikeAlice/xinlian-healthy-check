#include"stdafx.h"
#include"ReportController.h"
#include"service/report/ReportService.h"

ReportJsonVO::Wrapper ReportController::execqueryReport(const IDQuery::Wrapper& query) {
	// ����һ��Service
	ReportService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ReportJsonVO::createShared();
	jvo->success(result);
	return jvo;

}
