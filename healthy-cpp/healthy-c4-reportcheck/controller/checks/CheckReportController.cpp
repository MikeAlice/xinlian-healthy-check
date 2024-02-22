#include "stdafx.h"
#include "CheckReportController.h"
#include "../../service/checks/CheckReportListService.h"
#include "../ApiDeclarativeServicesHelper.h"
/*
* contrller ��ȡ�����б�ʵ����
* ������Z
*/
CheckReportListPageJsonVO::Wrapper CheckReportController::execCheckReport(const CheckReportQuery::Wrapper& query) {
	// ����һ��Service
	CheckReportListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = CheckReportListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}