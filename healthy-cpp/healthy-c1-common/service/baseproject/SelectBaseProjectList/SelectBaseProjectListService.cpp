#include "SelectBaseProjectListService.h"
#include "../../../dao/baseproject/SelectBaseProject/SelectBaseProjectDAO.h"

SelectBaseProjectListPageDTO::Wrapper SelectBaseProjectListService::listAll(const SelectBaseProjectListQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = SelectBaseProjectListPageDTO::createShared();

	auto& records = query->records;//SelectBaseProjectQuery的List


	auto baseproject_list = oatpp::List<oatpp::Object<SelectBaseProjectDTO>>::createShared();


	//转换为处理SelectBaseProjectQuery, 利用它的dao与do完成查询.
	auto list_query = SelectBaseProjectQuery::createShared();

	list_query->pageIndex = query->pageIndex;
	list_query->pageSize = query->pageSize;

	SelectBaseProjectDAO dao;
	auto result = dao.selectWithPage(list_query);

	for (auto& item_do : result) {
		auto dto = SelectBaseProjectDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, item_do,
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

			baseproject_list->push_back(std::move(dto));
	}

	//转交查询好的列表
	SelectBaseProjectListDTO::Wrapper baseprojectlist_wrapper = SelectBaseProjectListDTO::createShared();
	baseprojectlist_wrapper->records = std::move(baseproject_list);
	//返回
	pages->addData(baseprojectlist_wrapper);
	return pages;
}