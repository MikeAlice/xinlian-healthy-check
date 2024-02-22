#include "JoinPersonListService.h"
#include "stdafx.h"
#include"../../dao/personlist/JoinPersonListDAO.h"


PersonListPageDTO::Wrapper JoinPersonListService::listAll(const JoinPersonListQuery::Wrapper& query)

{
	// 构建返回对象
	auto pages = PersonListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	JoinPersonListDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<JoinPersonListDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (JoinPersonListDO sub : result)
	{
		auto dto = JoinPersonListDTO::createShared();
			dto->testNum = sub.getTestNum();
		 	//	dto->name = sub.getName();
		 	//	dto->sex = sub.getSex();
		 	//	dto->age = sub.getAge();
		    ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, testNum, TestNum, name, Name, sex, Sex, age, Age, idCard, IdCard, workStateText, WorkStateText, hazardFactor, HazardFactor, checkDate, CheckDate, comments, Comments);
			pages->addData(dto);

	}
	return pages;
}

//uint64_t JoinPersonListService::saveData(const JoinPersonListDTO::Wrapper& dto)
//{
//	return 0;
//}
//
//bool JoinPersonListService::updateData(const JoinPersonListDTO::Wrapper& dto)
//{
//	return false;
//}
//
//bool JoinPersonListService::removeData(uint64_t id)
//{
//	return false;
//}
