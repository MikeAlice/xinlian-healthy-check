#include "stdafx.h"
#include "SelectBaseProjectService.h"
#include "../../../dao/baseproject/SelectBaseProject/SelectBaseProjectDAO.h"

SelectBaseProjectPageDTO::Wrapper SelectBaseProjectService::listAll(const SelectBaseProjectQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = SelectBaseProjectPageDTO::createShared();

	// 查询数据总条数
	SelectBaseProjectDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	auto result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (SelectBaseProjectDO sub : result)
	{
		auto dto = SelectBaseProjectDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			id, Id,
			code, Code,
			name, Name,
			short_name, ShortName,
			order_num, OrderNum,
			office_id, OfficeId,
			office_name, OfficeName,
			unit_code, UnitCode,
			unit_name, UnitName,
			default_value, DefaultValue,
			result_type, ResultType,
			in_conclusion, InConclusion,
			in_report, InReport,
			relation_code, RelationCode,
			del_flag, DelFlag,
			create_id, CreateId,
			create_time, CreateTime,
			update_id, UpdateId,
			update_time, UpdateTime,
			delete_id, DeleteId,
			delete_time, DeleteTime,
			department_id, DepartmentId)

		pages->addData(dto);

	}
	return pages;
}