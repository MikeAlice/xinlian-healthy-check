#include "stdafx.h"
#include "PreviewReportController.h"
#include "../../service/previews/PreviewReportService.h"
#include "../ApiDeclarativeServicesHelper.h"

PreviewReportJsonVO::Wrapper  PreviewReportController::execPreviewReport(const PreviewReportQuery::Wrapper& query) {
	// ����һ��Service
	PreviewReportService service;
	// ��ѯ����
	auto result = service.listId(query);
	// ��Ӧ���
	auto jvo = PreviewReportJsonVO::createShared();
	jvo->success(result);
	return jvo;
}