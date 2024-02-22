#include "PlanProListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
PlanProListJsonVO::Wrapper PlanProListController::execQueryPlanProList(const PayloadDTO& payload)
{
	// ����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// �����ͻ��˶���
	API_CLIENT_CREATE(ac, om, PlanProListApiClient, "query-planprolist-api");
	// ���ؽ��
	return ac->queryPlanProList(token)->readBodyToDto<PlanProListJsonVO::Wrapper>(om);
}

