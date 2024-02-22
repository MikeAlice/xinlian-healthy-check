#include "stdafx.h"
#include "../../dao/GetPD/GetPDDAO.h"
#include "GetPDService.h"

GetPDPageDTO::Wrapper GetPDService::listAll(const GetPDQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = GetPDPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	GetPDDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<GetPDDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (GetPDDO sub : result)
	{
		auto dto = GetPDDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, sex, Sex, name, Name, work_name, Work_name, id_card, Id_card,age,Age, phone, Phone)
			pages->addData(dto);
	}
	return pages;
}
