#include "stdafx.h"
#include "ReportListController.h"
#include "../../service/reportlist/ReportListService.h"
#include "../ApiDeclarativeServicesHelper.h"
ReportListPageJsonVO::Wrapper ReportListController::execQueryReportList(const ReportListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	ReportListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = ReportListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
