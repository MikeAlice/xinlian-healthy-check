#pragma once
#ifndef _HEALTH_CERTIFICATE_LIST_DAO_
#define _HEALTH_CERTIFICATE_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/healthcertificatelist/HealthCertificateListDO.h"
#include "../../domain/query/healthcertificatelist/HealthCertificateQuery.h"

/**
 * 示例表数据库操作实现
 */
class HealthCertificateListDAO : public BaseDAO
{
public:
	// 统计数据条数
	uint64_t count(const HealthCertificateListQuery::Wrapper& query);
	// 分页查询数据
	list<HealthCertificateListDO> selectWithPage(const HealthCertificateListQuery::Wrapper& query);
};
#endif // !_HEALTH_CERTIFICATE_LIST_DAO_
