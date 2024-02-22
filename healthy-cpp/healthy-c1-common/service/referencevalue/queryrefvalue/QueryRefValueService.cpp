#include "stdafx.h"
#include "QueryRefValueService.h"
#include "dao/referencevalue/queryrefvalue/QueryRefValueDAO.h"
#include "domain/do/referencevalue/QueryRefValueDO.h"

RefValuePageDTO::Wrapper QueryRefValueService::listAll(const RefValuePageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RefValuePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	QueryRefValueDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	std::list<QueryRefValueDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (QueryRefValueDO sub: result)
	{
		auto dto = RefValueDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			id, Id, base_project_id, BaseProjectId, allow_sex, AllowSex, 
			min_age, MinAge, max_age, MaxAge, healthy_value, HealthyValue,
			occupation_value, OccupationValue, department_id, DepartmentId, 
			create_id, CreateId, create_time, CreateTime)
			pages->addData(dto);
	}
	return pages;
}
