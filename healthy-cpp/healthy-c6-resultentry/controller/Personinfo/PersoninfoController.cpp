#include "stdafx.h"
#include "PersoninfoController.h"

PersoninfoPageJsonVO::Wrapper PersoninfoController::execQueryByPersoninfo(const PersoninfoQuery::Wrapper& gpq)
{
	// ����һ��Service
	PersoninfoService service;
	// ��ѯ����
	auto result = service.listAll(gpq);
	// ��Ӧ���
	auto jvo = PersoninfoPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}