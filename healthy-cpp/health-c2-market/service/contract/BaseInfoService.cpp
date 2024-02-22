#include "stdafx.h"
#include "BaseInfoService.h"
#include "../../dao/contract/BaseInfoDAO.h"

BaseInfoPageDTO::Wrapper BaseInfoService::listAll(const BaseInfoQuery::Wrapper& query)
{
	// �������ض���
	auto pages = BaseInfoPageDTO::createShared();
	
	// ��ѯ����������
	BaseInfoDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	list<BaseInfoDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (BaseInfoDO sub : result)
	{
		auto dto = BaseInfoDTO::createShared();
		// 		dto->id = sub.getId();
		// 		dto->name = sub.getName();
		// 		dto->sex = sub.getSex();
		// 		dto->age = sub.getAge();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, signingTime, SigningTime, groupUnitName, GroupUnitName, auditState, AuditState)
		pages->addData(dto);

	}
	return pages;
}