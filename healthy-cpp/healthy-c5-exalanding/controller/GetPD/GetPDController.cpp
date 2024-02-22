#include "stdafx.h"
#include "GetPDController.h"
#include "../../service/GetPD/GetPDService.h"
#include "../ApiDeclarativeServicesHelper.h"

GetPDPageJsonVO::Wrapper GetPDController::execQueryGetPD(const GetPDQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	GetPDService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = GetPDPageJsonVO::createShared();
	jvo->success(result);
	return jvo;;
}
