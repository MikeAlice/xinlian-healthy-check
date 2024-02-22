#include "PlanNameListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"

PlanNameListPageJsonVO::Wrapper PlanNameListController::execQueryPlanNameList(const PlanNameListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// �����ͻ��˶���
	API_CLIENT_CREATE(ac, om, PlanNameListApiClient, "query-plannamelist-api");
	// ���ؽ��
	return ac->queryPlanNameList(token, query->pageIndex, query->pageSize, URIUtil::urlEncode(query->keyword))->readBodyToDto<PlanNameListPageJsonVO::Wrapper>(om);
}
