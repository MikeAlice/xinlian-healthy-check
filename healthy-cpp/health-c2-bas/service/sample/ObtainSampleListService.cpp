
#include "stdafx.h"
#include "ObtainSampleListService.h"
#include "../../dao/ObtainSampleList/ObtainSampleListDAO.h"
//ObtainSampleListService
ObtainSampleListPageDTO::Wrapper ObtainSampleListService::listAll(const ObtainSampleListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = ObtainSampleListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	ObtainSampleListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<ObtainSampleListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (ObtainSampleListDO sub : result)
	{
		auto dto = ObtainSampleListDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name,  code, Code,
			liscode, Liscode)
			pages->addData(dto);

	}
	return pages;
}

uint64_t ObtainSampleListService::saveData(const ObtainSampleListDTO::Wrapper& dto)
{
	// 组装DO数据
	ObtainSampleListDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Code, code,
		Liscode, liscode)
		// 执行数据添加
		ObtainSampleListDAO dao;
	return dao.insert(data);
}

bool ObtainSampleListService::updateData(const ObtainSampleListDTO::Wrapper& dto)
{
	// 组装DO数据
	ObtainSampleListDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Code, code,
		Liscode, liscode)
		// 执行数据修改
		ObtainSampleListDAO dao;
	return dao.update(data) == 1;
}

bool ObtainSampleListService::removeData(uint64_t id)
{
	ObtainSampleListDAO dao;
	return dao.deleteById(id) == 1;
}
