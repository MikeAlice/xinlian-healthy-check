#include "stdafx.h"
#include "ReportListService.h"
#include "../../dao/reportlist/ReportListDAO.h"

ReportListPageDTO::Wrapper ReportListService::listAll(const ReportListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ReportListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ReportListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ReportListDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ReportListDO sub : result)
	{
		auto dto = ReportListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			test_num, Test_num,
			id_card, Id_card,
			person_name, Person_name,
			sex, Sex,
			age, Age,
			check_date, Check_date,
			check_result, Check_result,
			physical_unit, Physical_unit,
			statu, Statu
		)
			pages->addData(dto);
	}
	return pages;
}