#include "StatisticalMessageService.h"
#include "stdafx.h"
#include "../../dao/statisticalmessage/StatisticalMessageDAO.h"

StatisticalMessagePageDTO::Wrapper StatisticalMessageService::listAll(const StatisticalMessageQuery::Wrapper& query)
{
	// �������ض���
	auto pages = StatisticalMessagePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	StatisticalMessageDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<StatisticalMessageDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (StatisticalMessageDO sub : result)
	{
		auto dto = StatisticalMessageDTO::createShared();
			dto->id = sub.getId();
			dto->isPass = sub.getIsPass();
		//	dto->age = sub.getAge();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, testNum, TestNum, name, Name, sex, Sex, age, Age, idCard, IdCard, workStateText, WorkStateText, hazardFactor, HazardFactor, checkDate, CheckDate, comments, Comments);
		pages->addData(dto);

	}
	return pages;
}
