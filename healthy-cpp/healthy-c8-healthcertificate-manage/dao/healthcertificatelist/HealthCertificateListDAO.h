#pragma once
#ifndef _HEALTH_CERTIFICATE_LIST_DAO_
#define _HEALTH_CERTIFICATE_LIST_DAO_
#include "BaseDAO.h"
#include "../../domain/do/healthcertificatelist/HealthCertificateListDO.h"
#include "../../domain/query/healthcertificatelist/HealthCertificateQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class HealthCertificateListDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const HealthCertificateListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<HealthCertificateListDO> selectWithPage(const HealthCertificateListQuery::Wrapper& query);
};
#endif // !_HEALTH_CERTIFICATE_LIST_DAO_
