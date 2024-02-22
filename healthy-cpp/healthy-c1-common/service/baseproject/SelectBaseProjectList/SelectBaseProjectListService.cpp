#include "SelectBaseProjectListService.h"
#include "../../../dao/baseproject/SelectBaseProject/SelectBaseProjectDAO.h"

SelectBaseProjectListPageDTO::Wrapper SelectBaseProjectListService::listAll(const SelectBaseProjectListQuery::Wrapper& query)
{
	// �������ض���
	auto pages = SelectBaseProjectListPageDTO::createShared();

	auto& records = query->records;//SelectBaseProjectQuery��List


	auto baseproject_list = oatpp::List<oatpp::Object<SelectBaseProjectDTO>>::createShared();


	//ת��Ϊ����SelectBaseProjectQuery, ��������dao��do��ɲ�ѯ.
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

	//ת����ѯ�õ��б�
	SelectBaseProjectListDTO::Wrapper baseprojectlist_wrapper = SelectBaseProjectListDTO::createShared();
	baseprojectlist_wrapper->records = std::move(baseproject_list);
	//����
	pages->addData(baseprojectlist_wrapper);
	return pages;
}