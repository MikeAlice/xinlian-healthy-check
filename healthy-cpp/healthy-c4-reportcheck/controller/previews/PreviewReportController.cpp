#include "stdafx.h"
#include "PreviewReportController.h"
#include "../../service/previews/PreviewReportService.h"
#include "../ApiDeclarativeServicesHelper.h"

PreviewReportJsonVO::Wrapper  PreviewReportController::execPreviewReport(const PreviewReportQuery::Wrapper& query) {
	// 定义一个Service
	PreviewReportService service;
	// 查询数据
	auto result = service.listId(query);
	// 响应结果
	auto jvo = PreviewReportJsonVO::createShared();
	jvo->success(result);
	return jvo;
}