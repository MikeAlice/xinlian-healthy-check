#include "GroupOrderListService.h"
#include"dao/Exalanding/GroupOrderListDAO.h"
GroupOrderListPageDTO::Wrapper GroupOrderListService::listAll(const GroupOrderListQuery::Wrapper& query)
{
	//�������ض���
	auto pages = GroupOrderListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	//��ѯ����������
	GroupOrderListDAO dao;
	uint64_t count = dao.count(query);
	if (count < 0) {
		return pages;
	}
	//��ҳ��ѯ
	pages->total = count;
	pages->calcPages();
	list<GroupOrderListDO>result = dao.selectWithPage(query);
	//��DOת����DTO
	for (GroupOrderListDO sub : result) {
		auto dto = GroupOrderListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, sex, Sex, groupUnitName, GroupUnitName, groupName, GroupName)
		pages->addData(dto);
	}
	return pages;
}
