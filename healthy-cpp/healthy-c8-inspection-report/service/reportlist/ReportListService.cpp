#include "stdafx.h"
#include "ReportListService.h"
#include "../../dao/reportlist/ReportListDAO.h"

ReportListPageDTO::Wrapper ReportListService::listAll(const ReportListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ReportListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ReportListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ReportListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
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