#include "stdafx.h"
#include "MedExamPrintReportService.h"
#include "../../dao/medexamprintreport/MedExamPrintReportDAO.h"



MedExamPrintReportPageDTO::Wrapper MedExamPrintReportService::listAll(const MedExamPrintReportQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = MedExamPrintReportPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	MedExamPrintReportDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<MedExamPrintReportDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (MedExamPrintReportDO sub : result)
	{
		auto dto = MedExamPrintReportDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age, statu, Statu, printState, PrintState, sporadicPhysical, SporadicPhysical)
			pages->addData(dto);

	}
	return pages;
}

