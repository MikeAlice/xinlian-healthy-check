#include "GroupOrderListService.h"
#include"dao/Exalanding/GroupOrderListDAO.h"
GroupOrderListPageDTO::Wrapper GroupOrderListService::listAll(const GroupOrderListQuery::Wrapper& query)
{
	//构建返回对象
	auto pages = GroupOrderListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	//查询数据总条数
	GroupOrderListDAO dao;
	uint64_t count = dao.count(query);
	if (count < 0) {
		return pages;
	}
	//分页查询
	pages->total = count;
	pages->calcPages();
	list<GroupOrderListDO>result = dao.selectWithPage(query);
	//将DO转换成DTO
	for (GroupOrderListDO sub : result) {
		auto dto = GroupOrderListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, sex, Sex, groupUnitName, GroupUnitName, groupName, GroupName)
		pages->addData(dto);
	}
	return pages;
}
