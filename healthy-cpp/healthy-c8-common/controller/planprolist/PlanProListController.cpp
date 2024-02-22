#include "PlanProListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
PlanProListJsonVO::Wrapper PlanProListController::execQueryPlanProList(const PayloadDTO& payload)
{
	// 构建凭证
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// 创建客户端对象
	API_CLIENT_CREATE(ac, om, PlanProListApiClient, "query-planprolist-api");
	// 返回结果
	return ac->queryPlanProList(token)->readBodyToDto<PlanProListJsonVO::Wrapper>(om);
}

