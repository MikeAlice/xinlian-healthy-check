#include "stdafx.h"
#include "../../dao/checkitem/BaseProjectDAO.h"
#include "BaseProejctService.h"

BaseProjectPageDTO::Wrapper BaseProjectService::listAll(const BaseProjectQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = BaseProjectPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	BaseProjectDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 查询数据
	pages->total = count;
	pages->calcPages();
	list<BaseProjectDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (BaseProjectDO sub : result)
	{
		auto dto = BaseProjectListDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, code, Code, name, Name, unit_name, Unit_name, healthy_value, Healthy_value,default_value, Default_value, result_type, Result_type)
			pages->addData(dto);

	}
	return pages;
}
