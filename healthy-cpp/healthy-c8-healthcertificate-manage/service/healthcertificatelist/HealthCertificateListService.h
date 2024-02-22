#pragma once
#ifndef _HEALTH_CERTIFICATE_LIST_SERVICE_
#define _HEALTH_CERTIFICATE_LIST_SERVICE_
#include <list>
#include "domain/vo/healthcertificatelist/HealthCertificateVO.h"
#include "domain/query/healthcertificatelist/HealthCertificateQuery.h"
#include "domain/dto/healthcertificatelist/HealthCertificateDTO.h"

/**
 * 示例服务实现，演示基础的示例服务实现
 */
class HealthCertificateListService
{
public:
	// 分页查询所有数据
	HealthCertificateListPageDTO::Wrapper listAll(const HealthCertificateListQuery::Wrapper& query);
};

#endif // !_HEALTH_CERTIFICATE_LIST_SERVICE_

