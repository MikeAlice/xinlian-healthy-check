#include "stdafx.h"
#include "QueryCritValueService.h"
#include "../../../domain/dto/database/CritValueDTO.h"
#include "../../../domain/query/database/CritValuePageQuery.h"
#include "../../../dao/querycritvaluedao/QueryCritValueDAO.h"


CritValuePageDTO::Wrapper QueryCritValueService::listAll(const CritValuePageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = CritValuePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	QueryCritValueDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	std::list<QueryCritValueDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
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