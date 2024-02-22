#include "stdafx.h"
#include "QueryCritValueService.h"
#include "../../../domain/dto/database/CritValueDTO.h"
#include "../../../domain/query/database/CritValuePageQuery.h"
#include "../../../dao/querycritvaluedao/QueryCritValueDAO.h"


CritValuePageDTO::Wrapper QueryCritValueService::listAll(const CritValuePageQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CritValuePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	QueryCritValueDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	std::list<QueryCritValueDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (QueryCritValueDO sub : result)
	{
		auto dto = CritValueDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO( dto,sub,
			id, Id, baseProjectId, BaseProjectId, allowSex, AllowSex,
			minAge, MinAge, maxAge, MaxAge, level, Level,
			type, Type, intervalValue, IntervalValue,departmentId, DepartmentId,
			createId, CreateId, createTime, CreateTime)
		pages->addData(dto);
	}
	return pages;
}