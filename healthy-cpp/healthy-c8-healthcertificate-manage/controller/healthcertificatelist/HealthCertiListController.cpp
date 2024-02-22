#include "stdafx.h"
#include "HealthCertiListController.h"
#include "../../service/healthcertificatelist/HealthCertificateListService.h"
#include "../ApiDeclarativeServicesHelper.h"


HealthCertificateListPageJsonVO::Wrapper HealthCertificateController::execQueryHealthCertificateList(const HealthCertificateListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	HealthCertificateListService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = HealthCertificateListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}