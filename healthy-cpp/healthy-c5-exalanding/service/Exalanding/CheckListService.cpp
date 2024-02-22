#include "stdafx.h"
#include "CheckListService.h"
#include "../../dao/Exalanding/CheckListDAO.h"

CheckListPageDTO::Wrapper CheckListService::listAll(const CheckListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CheckListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	CheckListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<CheckListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (CheckListDO sub : result)
	{
		auto dto = CheckListDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, item, Item, id_card, Id_card, discount, Discount, discount_price, Discount_price, physical_type, Physical_type)
			pages->addData(dto);

	}
	return pages;
}

uint64_t CheckListService::saveData(const CheckListDTO::Wrapper& dto)
{
	// 组装DO数据
	CheckListDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Item, item, Id_card, id_card, Discount, discount, Discount_price, discount_price, Physical_type, physical_type)
		// 执行数据添加
		CheckListDAO dao;
	return dao.insert(data);
}

bool CheckListService::updateData(const CheckListDTO::Wrapper& dto)
{
	// 组装DO数据
	CheckListDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Item, item, Id_card, id_card, Discount, discount, Discount_price, discount_price, Physical_type, physical_type)
		// 执行数据修改
		CheckListDAO dao;
	return dao.update(data) == 1;
}

bool CheckListService::removeData(uint64_t id)
{
	CheckListDAO dao;
	return dao.deleteById(id) == 1;
}
