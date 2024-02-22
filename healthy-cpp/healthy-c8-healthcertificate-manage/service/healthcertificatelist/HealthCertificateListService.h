#pragma once
#ifndef _HEALTH_CERTIFICATE_LIST_SERVICE_
#define _HEALTH_CERTIFICATE_LIST_SERVICE_
#include <list>
#include "domain/vo/healthcertificatelist/HealthCertificateVO.h"
#include "domain/query/healthcertificatelist/HealthCertificateQuery.h"
#include "domain/dto/healthcertificatelist/HealthCertificateDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class HealthCertificateListService
{
public:
	// ��ҳ��ѯ��������
	HealthCertificateListPageDTO::Wrapper listAll(const HealthCertificateListQuery::Wrapper& query);
};

#endif // !_HEALTH_CERTIFICATE_LIST_SERVICE_

