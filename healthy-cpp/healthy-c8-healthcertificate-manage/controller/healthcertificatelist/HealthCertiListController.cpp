#include "stdafx.h"
#include "HealthCertiListController.h"
#include "../../service/healthcertificatelist/HealthCertificateListService.h"
#include "../ApiDeclarativeServicesHelper.h"


HealthCertificateListPageJsonVO::Wrapper HealthCertificateController::execQueryHealthCertificateList(const HealthCertificateListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	HealthCertificateListService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = HealthCertificateListPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}