#include "TermService.h"
#include "stdafx.h"
#include "../../dao/term/TermListDAO.h"



TermListPageDTO::Wrapper TermService::listAll(const TermQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = TermListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	TermListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<TermListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (TermListDO sub : result)
	{
		auto dto = TermListDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, officeId, OfficeId, hazardFactorsText, HazardFactorsText,
			inspectType, InspectType, content, Content, workStateText, WorkStateText)
			pages->addData(dto);

	}
	return pages;
}

uint64_t TermService::saveData(const TermListDTO::Wrapper& dto)
{
	// 组装DO数据
	TermListDO data;
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, OfficeId, officeId, HazardFactorsText, hazardFactorsText,
		InspectType, inspectType, Content, content, WorkStateText, workStateText)
		// 执行数据添加
		TermListDAO dao;
	return dao.insert(data);
}

bool TermService::updateData(const TermListDTO::Wrapper& dto)
{
	// 组装DO数据
	TermListDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, OfficeId, officeId, HazardFactorsText, hazardFactorsText,
		InspectType, inspectType, Content, content, WorkStateText, workStateText)
		// 执行数据修改
		TermListDAO dao;
	return dao.update(data) == 1;

}

bool TermService::removeData(uint64_t id)
{
	TermListDAO dao;
	return dao.deleteById(id) == 1;

}
