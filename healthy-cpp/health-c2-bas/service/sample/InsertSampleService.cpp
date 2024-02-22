
#include "stdafx.h"
#include "InsertSampleService.h"
#include "../../dao/InsertSample/InsertSampleDAO.h"

InsertSamplePageDTO::Wrapper InsertSampleService::listAll(const InsertSampleQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = InsertSamplePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	InsertSampleDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<InsertSampleDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (InsertSampleDO sub : result)
	{
		auto dto = InsertSampleDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, name, Name, spec, Spec, code, Code,
			is_print, Is_print, capacity, Capacity, barcode_num, Barcode_num,
			need_take_blood, Need_take_blood, order_num, Order_num,
			liscode, Liscode)
			pages->addData(dto);

	}
	return pages;
}

uint64_t InsertSampleService::saveData(const InsertSampleDTO::Wrapper& dto)
{
	// 组装DO数据
	InsertSampleDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,Id,id, Name, name, Spec, spec, Code, code,
		Is_print, is_print, Capacity, capacity, Barcode_num, barcode_num,
		Need_take_blood, need_take_blood, Order_num, order_num,
		Liscode, liscode,Del_flag,del_flag)
		// 执行数据添加
	InsertSampleDAO dao;
	return dao.insert(data);
}




//
//bool InsertSampleService::updateData(const InsertSampleDTO::Wrapper& dto)
//{
//	// 组装DO数据
//	InsertSampleDO data;
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Spec, spec, Code, code,
//		Is_print, is_print, Capacity, capacity, Barcode_num, barcode_num,
//		Need_take_blood, need_take_blood, Order_num, order_num,
//		Liscode, liscode)
//		// 执行数据修改
//		InsertSampleDAO dao;
//	return dao.update(data) == 1;
//}
//
//bool InsertSampleService::removeData(uint64_t id)
//{
//	InsertSampleDAO dao;
//	return dao.deleteById(id) == 1;
//}
