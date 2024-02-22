#include "stdafx.h"
#include "ProfessionalHistoryService.h"
#include "../../dao/unknownmoduleprofessionalhistory/ProfessionalHistoryDAO.h"
#include "../../domain/do/unknownmoduleprofessionalhistory/ProfessionalHistoryDO.h"
#include "../../../nacos-register/Macros.h"
#include "../../../arch-demo/Macros.h"
// #include "../../dao/GroupPerson/GroupPersonDAO.h" ����

ProfessionalHistoryPageDTO::Wrapper ProfessionalHistoryService::listAll(const ProfessionalHistoryQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ProfessionalHistoryPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ProfessionalHistoryDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ProfessionalHistoryDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ProfessionalHistoryDO sub : result)
	{
		auto dto = ProfessionalHistoryDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, person_id, Person_id, start_date, Start_date, end_date, End_date, work_unit, Work_unit, department, Department, work_type_text, Work_type_text, hazard_factors_text, Hazard_factors_text, protective_measures, Protective_measures, contact_time, Contact_time)
			pages->addData(dto);
	}
	return pages;
}
