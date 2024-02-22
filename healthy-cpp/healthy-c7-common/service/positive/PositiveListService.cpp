#include "stdafx.h"
#include "PositiveListService.h"
#include "../../dao/positive/PositiveListDAO.h"

PositiveListPageDTO::Wrapper PositiveListService::listAll(const PositiveQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = PositiveListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	PositiveListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<PositiveListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (PositiveListDO sub : result)
	{
		auto dto = PositiveListDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, personName, PersonName, test_num, Test_Num, officeName, OfficeName, order_group_item_project_name, Order_Group_Item_Project_Name, result, Result, unit_name, Unit_Name, scope, Scope, crisis_degree, Crisis_Degree, checkDate, CheckDate)
			pages->addData(dto);

	}
	return pages;
}
/*
uint64_t PositiveListService::saveData(const PositiveListDTO::Wrapper& dto)
{
	// 组装DO数据
	PositiveListDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	// ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age)
		// 执行数据添加
		PositiveListDO dao;
	return dao.insert(data);
}
*/