#include "stdafx.h"
#include "GroupPersonController.h"

GroupPersonPageJsonVO::Wrapper GroupPersonController::execQueryByGroupPerson(const GroupPersonQuery::Wrapper& gpq)
{
	// ����һ��Service
	GroupPersonService service;
	// ��ѯ����
	auto result = service.listAll(gpq);
	// ��Ӧ���
	auto jvo = GroupPersonPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}