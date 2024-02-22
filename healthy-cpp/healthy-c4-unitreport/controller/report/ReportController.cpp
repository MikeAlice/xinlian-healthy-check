#include"stdafx.h"
#include"ReportController.h"
#include"service/report/ReportService.h"

ReportJsonVO::Wrapper ReportController::execqueryReport(const IDQuery::Wrapper& query) {
	// 定义一个Service
	ReportService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ReportJsonVO::createShared();
	jvo->success(result);
	return jvo;

}
