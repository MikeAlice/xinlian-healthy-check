#include "JobNameListController.h"
#include "stdafx.h"
#include "../ApiDeclarativeServicesHelper.h"
JobNameListPageJsonVO::Wrapper JobNameListController::execQueryJobNameList(const JobNameListQuery::Wrapper& query, const PayloadDTO& payload)
{
	// �����ͻ��˶���
	API_CLIENT_CREATE(ac, om, JobNameListApiClient, "dictionary-list-api");
	// ����ƾ֤
	std::string token = PayloadDTO::getTokenPrefix() + payload.getToken();
	// ���ز�ѯ���
	return ac->queryJobNameList(token, query->pageIndex, query->pageSize, URIUtil::urlEncode(query->keyword))->readBodyToDto<JobNameListPageJsonVO::Wrapper>(om);
}
