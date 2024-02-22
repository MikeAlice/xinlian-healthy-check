#include "stdafx.h"
#include "CheckReportController.h"
#include "../../service/checks/CheckReportListService.h"
#include "../ApiDeclarativeServicesHelper.h"
/*
* contrller 获取报告列表实体类
* 负责人Z
*/
CheckReportListPageJsonVO::Wrapper CheckReportController::execCheckReport(const CheckReportQuery::Wrapper& query) {
	// 定义一个Service
	CheckReportListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CheckReportListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}