#include "stdafx.h"
#include "BasicInformationService.h"
#include "../../dao/unknownmodulebasicinformation/BasicInformationDAO.h"
#include "../../domain/do/unknownmodulebasicinformation/BasicInformationDO.h"
#include "../../../nacos-register/Macros.h"
#include "../../../arch-demo/Macros.h"
// #include "../../dao/GroupPerson/GroupPersonDAO.h" ����

BasicInformationPageDTO::Wrapper BasicInformationService::listAll(const BasicInformationQuery::Wrapper& query)
{
	// �������ض���
	auto pages = BasicInformationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	BasicInformationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<BasicInformationDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (BasicInformationDO sub : result)
	{
		auto dto = BasicInformationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, person_id, Person_id, job, Job, work_year, Work_year, work_month, Work_month, exposure_start_date, Exposure_start_date, education, Education, family_address, Family_address, marriage_date, Marriage_date)
		pages->addData(dto);
	}
	return pages;
}
