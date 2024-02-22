#include "stdafx.h"
#include "HealthCertificateListService.h"
#include "../../dao/healthcertificatelist/HealthCertificateListDAO.h"

HealthCertificateListPageDTO::Wrapper HealthCertificateListService::listAll(const HealthCertificateListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = HealthCertificateListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	HealthCertificateListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<HealthCertificateListDO> result = dao.selectWithPage(query);

	// 将DO转换成DTO
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