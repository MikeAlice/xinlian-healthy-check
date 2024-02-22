#include "stdafx.h"
#include "HealthCertificateListService.h"
#include "../../dao/healthcertificatelist/HealthCertificateListDAO.h"

HealthCertificateListPageDTO::Wrapper HealthCertificateListService::listAll(const HealthCertificateListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = HealthCertificateListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	HealthCertificateListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<HealthCertificateListDO> result = dao.selectWithPage(query);

	// ��DOת����DTO
	for (HealthCertificateListDO sub : result)
	{
		auto dto = HealthCertificateListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			health_ccertificate, Health_ccertificate,
			name, Name,
			sex, Sex,
			age, Age,
			term_of_validity, Term_of_validity,
			unit_of_issue, Unit_of_issue,
			is_upload, Is_upload
		)
			pages->addData(dto);
	}
	return pages;
}