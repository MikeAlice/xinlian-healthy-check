#include "stdafx.h"
#include "CheckReportListService.h"
#include "../../dao/checks/CheckReportListDAO.h"
/*
* service ʵ��
* ������ Z
*/
CheckReportListPageDTO::Wrapper CheckReportListService::listAll(const CheckReportQuery::Wrapper& query)
{
	// �������ض���
	auto pages = CheckReportListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	CheckReportListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<CheckReportListDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (CheckReportListDO sub : result)
	{
		auto dto = CheckReportListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, person_name, Person_name, sex, Sex, age, Age, statu, Statu, print_state, Print_state, sporadic_physical, Sporadic_physical)
		pages->addData(dto);
	}
	return pages;
}

