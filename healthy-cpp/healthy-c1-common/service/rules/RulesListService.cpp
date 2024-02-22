#include "stdafx.h"
#include "RulesListService.h"
#include "../../dao/rules/RulesListDAO.h"

RulesListPageDTO::Wrapper RulesListService::listAll(const RulesListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = RulesListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	RulesListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<RulesListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (RulesListDO sub : result)
	{
		auto dto = RulesListDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, short_name, Short_name, type,Type)
		pages->addData(dto);

	}
	return pages;
}

//RulesListPageDTO::Wrapper RulesListService::selectById(const RulesListQuery::Wrapper& query)
//{
//
//	return RulesListPageDTO::Wrapper();
//}


bool RulesListService::updateData(const RulesListDTO::Wrapper& dto)
{
	// 组装DO数据
	RulesListDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Short_name, short_name, Type, type, Id, id)
		// 执行数据修改
		RulesListDAO dao;
	return dao.update(data) == 1;
}
