#include "stdafx.h"
#include "BasicInformationService.h"
#include "../../dao/unknownmodulebasicinformation/BasicInformationDAO.h"
#include "../../domain/do/unknownmodulebasicinformation/BasicInformationDO.h"
#include "../../../nacos-register/Macros.h"
#include "../../../arch-demo/Macros.h"
// #include "../../dao/GroupPerson/GroupPersonDAO.h" 待定

BasicInformationPageDTO::Wrapper BasicInformationService::listAll(const BasicInformationQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = BasicInformationPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	BasicInformationDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<BasicInformationDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (BasicInformationDO sub : result)
	{
		auto dto = BasicInformationDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, person_id, Person_id, job, Job, work_year, Work_year, work_month, Work_month, exposure_start_date, Exposure_start_date, education, Education, family_address, Family_address, marriage_date, Marriage_date)
		pages->addData(dto);
	}
	return pages;
}
