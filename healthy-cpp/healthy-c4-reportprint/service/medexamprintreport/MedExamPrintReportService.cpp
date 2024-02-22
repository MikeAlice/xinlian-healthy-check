#include "stdafx.h"
#include "MedExamPrintReportService.h"
#include "../../dao/medexamprintreport/MedExamPrintReportDAO.h"



MedExamPrintReportPageDTO::Wrapper MedExamPrintReportService::listAll(const MedExamPrintReportQuery::Wrapper& query)
{
	// �������ض���
	auto pages = MedExamPrintReportPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	MedExamPrintReportDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<MedExamPrintReportDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (MedExamPrintReportDO sub : result)
	{
		auto dto = MedExamPrintReportDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age, statu, Statu, printState, PrintState, sporadicPhysical, SporadicPhysical)
			pages->addData(dto);

	}
	return pages;
}

