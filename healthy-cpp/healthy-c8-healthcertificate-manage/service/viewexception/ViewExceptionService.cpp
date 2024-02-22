#include "stdafx.h"
#include "ViewExceptionService.h"
#include "../../dao/viewexception/ViewExceptionDAO.h"

ViewExceptionDTO::Wrapper ViewExceptionService::getData(const ViewExceptionQuery::Wrapper& query)
{
	// �������ض���
	auto obj = ViewExceptionDTO::createShared();

	// ��ѯ����������
	ViewExceptionDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return obj;
	}

	list<ViewExceptionDO> result = dao.selectByID(query);

	for (ViewExceptionDO sub : result)
	{
		auto dto = ViewExceptionDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, exception_message, Exception_message)
			return dto;
	}
	return obj;
}