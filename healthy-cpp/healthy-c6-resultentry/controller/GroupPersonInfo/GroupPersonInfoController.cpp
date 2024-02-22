#include"stdafx.h"
#include"GroupPersonInfoController.h"

#include "domain/GlobalInclude.h"
#include "./service/GroupPersonInfo/GroupPersonInfoService.h"

// ʵ����Ա�����ѯ�ӿں���
GroupPersonInfoJsonVO::Wrapper GroupPersonInfoController::queryPersonInfo(const GroupPersonInfoQuery::Wrapper& query)
{
	// ����Service
	GroupPersonInfoService service;
	// ��ѯ����
	auto result = service.queryInfo(query);
	// ��Ӧ���
	auto jvo = GroupPersonInfoJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
