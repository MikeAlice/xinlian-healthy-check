#include "stdafx.h"
#include "GetPDController.h"
#include "../../service/GetPD/GetPDService.h"
#include "../ApiDeclarativeServicesHelper.h"

GetPDPageJsonVO::Wrapper GetPDController::execQueryGetPD(const GetPDQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	GetPDService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = GetPDPageJsonVO::createShared();
	jvo->success(result);
	return jvo;;
}
