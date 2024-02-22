#include "stdafx.h"
#include "CheckReportListService.h"
#include "../../dao/checks/CheckReportListDAO.h"
/*
* service 实体
* 负责人 Z
*/
CheckReportListPageDTO::Wrapper CheckReportListService::listAll(const CheckReportQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CheckReportListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	CheckReportListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<CheckReportListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (CheckReportListDO sub : result)
	{
		auto dto = CheckReportListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, person_name, Person_name, sex, Sex, age, Age, statu, Statu, print_state, Print_state, sporadic_physical, Sporadic_physical)
		pages->addData(dto);
	}
	return pages;
}

