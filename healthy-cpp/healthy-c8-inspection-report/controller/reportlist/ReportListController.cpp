#include "stdafx.h"
#include "ReportListController.h"
#include "../../service/reportlist/ReportListService.h"
#include "../ApiDeclarativeServicesHelper.h"
ReportListPageJsonVO::Wrapper ReportListController::execQueryReportList(const ReportListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	ReportListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ReportListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
